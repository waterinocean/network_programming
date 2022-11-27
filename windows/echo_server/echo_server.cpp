#include <WinSock2.h>
#include <iostream>
#include <string>

using namespace std;

void err_handling(const char* err_msg)
{
    cout << err_msg << endl;
    exit(1);
}

int main(int argc, char* argv[])
{
    //check usage - params number
    if (argc != 2)
        err_handling("Usage: exe_name <port>.");

    //declare needed variable - network
    WSADATA wsa_data;
    SOCKET sock_server, sock_client;
    SOCKADDR_IN serv_addr;
    string msg;

    //init socket library
    if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0)
        err_handling("startup() error!");

    //create socket
    sock_server = socket(PF_INET, SOCK_STREAM, 0);
    if (sock_server == INVALID_SOCKET)
        err_handling("socket() error!");

    //init server addr
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    //bind socket
    if (0 != bind(sock_server, (SOCKADDR *)&serv_addr, sizeof(serv_addr)))
        err_handling("bind() error!");

    //start listen
    if (0 != listen(sock_server, 0))
        err_handling("listen() error!");

    //accept
    SOCKADDR_IN clnt_addr;
    int sz_clnt_addr = sizeof(clnt_addr);
    int clnt_sock_num = 0;
    while (clnt_sock_num < 5)
    {
        sock_client = accept(sock_server, (SOCKADDR *)&clnt_addr, &sz_clnt_addr);
        if (sock_client == INVALID_SOCKET)
            err_handling("accept() error!");

        //recv
        char *recv_msg = new char[100];
        int str_len = recv(sock_client, recv_msg, 30, 0);
        if (str_len == -1)
            err_handling("recv() error!");

        //edit msg and send
        cout << "recv msg: " << recv_msg << endl;
        if (-1 == send(sock_client, recv_msg, 30, 0))
            err_handling("send() error!");

        //close socket
        closesocket(sock_client);

        clnt_sock_num++;
    }
    //close server socket
    closesocket(sock_server);

    //release socket library
    WSACleanup();

    return 0;
}
