#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void errorHandling(string msg);
void recvFile(int socket, string file);

int main(void)
{
    int clntSock = socket(PF_INET, SOCK_STREAM, 0);
    if (-1 == clntSock)
    {
        errorHandling("socket() error");
    }
    string serverIp = "127.0.0.1";
    int port = 5050;
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(serverIp.c_str());
    serverAddr.sin_port = htons(port);
    if (-1 == connect(clntSock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)))
    {
        errorHandling("connect() error");
    }

    string file = "./client_data/recveive.cpp";
    recvFile(clntSock, file);
    close(clntSock);
    return 0;
}

void errorHandling(string msg)
{
    cout << msg << endl;
    exit(1);
}

void recvFile(int socket, string file)
{
    ofstream f(file, std::ios_base::out);
    char msg[1024];
    int len = read(socket, msg, 1024);
    f.write(msg, len);
    f.close();
}
