#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

using namespace std;

void errorHandling(const char* msg);
int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " <ip> <port>" << endl;
        exit(1);
    }

    int clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1)
    {
        errorHandling("socket() error");
    }

    string ip = argv[1];
    int port = atoi(argv[2]);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(ip.c_str());
    serverAddr.sin_port = htons(port);

    if (-1 ==connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)))
    {
        errorHandling("connect() error");
    }

    char message[30] = "";
    int len = read(clientSocket, message, sizeof(message));
    cout << "read: " << message << " len: " << len << endl;
    close(clientSocket);
    return 0;
}

void errorHandling(const char* msg)
{
    cout << msg << endl;
    exit(1);
}