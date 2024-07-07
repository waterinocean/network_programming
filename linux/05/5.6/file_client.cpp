#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include <fstream>
#include <string>
#include "protocol.h"

using namespace std;

void errorHandling(string msg);
void recvFile(int socket, string file);
void sendReq(int socket);

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

    //send req
    sendReq(clntSock);

    //receive file
    string file = "./data/recveive.cpp";
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
    char msg[4096];
    int len = read(socket, msg, 4096);
    printf("receive msg: %d\n", len);
    LData data;
    if (len <= 0 || !unpack(msg, len, data))
    {
        return;
    }
    ofstream f(file, std::ios_base::out);
    switch (data.header.command)
    {
    case LCOMMAND_ACK(LCOMMAND_File):
        cout << "receive file ack, save file." << endl;
        f.write(data.data, data.header.dataLen);
        f.close();
        break;
    default:
        break;
    }
}

void sendReq(int socket)
{
    cout << "send req started" << endl;
    char msg[50];
    int msgLen = 0;
    reqFile(msg, msgLen);
    if (msgLen > 0)
    {
        write(socket, msg, msgLen);
    }
    cout << "send req finished" << endl;
}
