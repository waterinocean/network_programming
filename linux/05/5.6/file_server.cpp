#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <unistd.h>
#include <thread>
#include <sys/types.h>
#include "protocol.h"

using namespace std;

void errorHandling(string msg);
void sendFile(int socket, string file);
void process(int socket);

int main(void)
{
    int serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (-1 == serverSocket)
    {
        errorHandling("socket() error");
    }

    int port = 5050;
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(port);

    if (-1 == bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)))
    {
        errorHandling("bind() error");
    }
    if (-1 == listen(serverSocket, 5))
    {
        errorHandling("listen() error");
    }
    cout << "server started: " << port << " thread id: " << gettid() << endl;
    int count = 0;
    while (1)
    {
        if (count >= 5)
        {
            break;
        }
        count++;
        struct sockaddr_in clientAddr;
        socklen_t clientAddrSize = sizeof(clientAddr);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrSize);
        if (-1 == clientSocket)
        {
            cout << "accept() error." << endl;
            break;
        }
        cout << "incoming client connect." << endl;
        std::thread t(process, clientSocket);
        t.detach();
    }
    cout << "server stopped." << endl;
    close(serverSocket);
    return 0;
}

void errorHandling(string msg)
{
    cout << msg << endl;
    exit(-1);
}

void sendFile(int socket, string file)
{
    char msg[4096];
    int msgLen = 0;
    ackFile(msg, msgLen, file.c_str());
    if (msgLen > 0)
    {
        printf("pack file ack, msgLen:%d\n", msgLen);
        write(socket, msg, msgLen);
    }
}

void process(int socket)
{
    cout << "thread started: " << gettid() << endl;

    char msg[100];
    LData data;
    std::string file = "./data/send.cpp";
    while (1)
    {
        memset(msg, 0, sizeof(msg));
        int len = read(socket, msg, 100);
        if (len <= 0)
        {
            continue;
        }

        if (!unpack(msg, len, data))
        {
            printf("unpack error.\n");
            continue;
        }
        switch (data.header.command)
        {
        case LCOMMAND_REQ(LCOMMAND_File):
            cout << "receive file req, send file." << endl;
            sendFile(socket, file);
            break;
        default:
            break;
        }
        break;
    }
    close(socket);
    cout << "thread quited." << endl;
}
