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
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <port>" << endl;
        exit(1);
    }

    int serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1)
    {
        errorHandling("socket() error");
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(atoi(argv[1]));

    if (-1 == bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)))
    {
        errorHandling("bind() error");
    }

    if (-1 == listen(serverSocket, 5))
    {
        errorHandling("listen() error");
    }

    struct sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrSize);
    if (-1 == clientSocket)
    {
        errorHandling("accept() error");
    }

    char message[30] = "Hello World";
    int len = sizeof(message);
    cout << "write len: " << len << endl;
    write(clientSocket, message, len);
    close(clientSocket);
    close(serverSocket);

    return 0;
}

void errorHandling(const char* msg)
{
    cout << msg << endl;
    exit(1);
}
