#include <thread>
#include <algorithm>
#include "tcp_server/tcp_server.h"
#include "tcp_server/server_observer.h"


using namespace std;

TcpServer::TcpServer(const int &srv_port): srv_port(srv_port)
{
    init_socket_use();

    create_socket();
    socket_bind_port();
}

TcpServer::~TcpServer()
{
    close_socket();
    clear_up();
}

void TcpServer::set_observer(std::shared_ptr<AbstractServerObserver> observer)
{
    srv_observer = observer;
}

void TcpServer::init_socket_use()
{
    if (WSAStartup(MAKEWORD(2, 2), &this->wsa_data) != 0)
        err_handling("WSAStartup() error!");
}

void TcpServer::clear_up()
{
    closesocket(this->srv_socket);
    if (WSACleanup() != 0)
        err_handling("WSACleanup() error!");
}

void TcpServer::create_socket()
{
    this->srv_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (this->srv_socket == INVALID_SOCKET)
        err_handling("socket() error! fail to create socket!");
}

void TcpServer::socket_bind_port()
{
    memset(&(this->srv_addr), 0, sizeof(this->srv_addr));
    this->srv_addr.sin_family = AF_INET;
    this->srv_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    this->srv_addr.sin_port = htons(this->srv_port);

    if (bind(this->srv_socket, (SOCKADDR*)&(this->srv_addr), sizeof(this->srv_addr)) == SOCKET_ERROR)
        err_handling("bind() error!");
}

void TcpServer::start()
{
    if (listen(this->srv_socket, 10) == SOCKET_ERROR)
        err_handling("listen() error!");

    std::thread thread_accept(&TcpServer::accept_clnt_sock, this);
    thread_accept.join();
}

//accept a socket and execute a thread for recv msg
void TcpServer::accept_clnt_sock()
{
    int n = 0, max_count = 10; //max serve 10 sock clients
    while (n <= max_count)
    {
        SOCKADDR_IN clnt_sock_addr;
        int clnt_sock_addr_size = sizeof(clnt_sock_addr);

        SOCKET clnt_socket = accept(this->srv_socket, (SOCKADDR*)&clnt_sock_addr, &clnt_sock_addr_size);
        if (clnt_socket == INVALID_SOCKET){
            err_handling("accept() error!");
        }

        if (srv_observer != nullptr)
            srv_observer->clnt_connect(inet_ntoa(clnt_sock_addr.sin_addr), ntohs(clnt_sock_addr.sin_port));

        shared_ptr<SocketInfo> clnt_sock_info = 
            make_shared<SocketInfo>(SocketInfo(clnt_socket, 
                                    clnt_sock_addr));
        this->clnt_sockets.push_back(clnt_sock_info);

        std::thread thread_recv(&TcpServer::read_msg, this, this->clnt_sockets.back());
        thread_recv.detach();

        n++;
    }
}

void TcpServer::read_msg(std::shared_ptr<SocketInfo> sock_info)
{
    char msg_recv[1000];
    int str_len = 0;
    while (1)
    {
        memset(msg_recv, 0, 1000);
        str_len = recv(sock_info->socket, msg_recv, 1000, 0);
        if (str_len > 0){
            if (srv_observer != nullptr)
                srv_observer->receive_msg(sock_info->ip, msg_recv);
        }
        else if (str_len == 0){
            if (srv_observer != nullptr)
                srv_observer->clnt_disconnect(sock_info->ip, ntohs(sock_info->socket_addr.sin_port));

            closesocket(sock_info->socket);
            
            auto it = std::find(this->clnt_sockets.begin(), this->clnt_sockets.end(), sock_info);
            if (it != this->clnt_sockets.end())
                this->clnt_sockets.erase(it);
            break;
        }else{
            cout << "recv() error: " << str_len << endl;
        }
    }
}

void TcpServer::send_msg(const std::string &ip, const std::string &msg)
{
    for (auto it: clnt_sockets)
    {
        if (it->ip == ip){
            send(it->socket, msg.c_str(), msg.size(), 0);
            break;
        }
    }
}

void TcpServer::close_socket()
{
    for (auto clnt: clnt_sockets)
    {
        closesocket(clnt->socket);
    }
    clnt_sockets.clear();
}

void TcpServer::err_handling(const std::string &err_msg)
{
    cout << err_msg << endl;
    exit(1);
}
