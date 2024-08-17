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
#include "lfileserver.h"
#include "ltcpserver.h"

using namespace std;

int main(void)
{
    LFileServer* server = new LFileServer();
    LTcpServer* tcp = new LTcpServer(5050);
    server->setServer(tcp);
    tcp->setServer(server);
    server->startServer();

    return 0;
}
