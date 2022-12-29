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
    if (argc != 3)
        err_handling("Usage: exe_name <ip> <port>.");

    // windows library, client socket and server address
    WSADATA wsaData;
    SOCKET sock_client;
    SOCKADDR_IN serv_addr;
    string msg;

    // init windows socket library
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        err_handling("windows socket library init error!");
    
     // create socket for client
    sock_client = socket(PF_INET, SOCK_STREAM, 0);
    if (sock_client == INVALID_SOCKET)
        err_handling("socket() error!");
 
    // set server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.S_un.S_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));
    
    // connect to server
    if (connect(sock_client, (SOCKADDR*)&serv_addr, sizeof(serv_addr)) != 0)
        err_handling("connect error!");

    // if connect success
    cout << "you can input something you want to say:" << endl;
    getline(cin, msg);
    int msg_len = sizeof(msg.c_str());
    // send msg
    send(sock_client, msg.c_str(), msg_len, 0);
    // recv msg
    char *recv_msg = new char[100];
    int str_len = recv(sock_client, const_cast<char *>(msg.c_str()), 30, 0);
    if (str_len == -1)
        err_handling("recv msg error!");
    cout << "recv msg:" << msg << endl;
    // close socket
    closesocket(sock_client);
    // release socket library
    WSACleanup();

    return 0;
}
