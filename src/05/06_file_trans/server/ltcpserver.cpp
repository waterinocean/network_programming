#include "ltcpserver.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <thread>
#include "lmsgparser.h"
#include "lfileserver.h"

LTcpServer::LTcpServer(int port)
    : m_port(port)
    , m_vecSocket({})
{
}

void LTcpServer::setServer(LFileServer *server)
{
    if (nullptr == server)
    {
        return;
    }
    m_server = server;
}

void LTcpServer::start(void)
{
    m_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (-1 == m_socket)
    {
        printf("socket() error.\n");
        return;
    }
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(m_port);
    if (-1 == bind(m_socket, (struct sockaddr*)&addr, sizeof(addr)))
    {
        printf("bind() error.\n");
        return;
    }
    if (-1 == listen(m_socket, 5))
    {
        printf("listen() error.\n");
        return;
    }
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
        int clientSocket = accept(m_socket, (struct sockaddr*)&clientAddr, &clientAddrSize);
        if (-1 == clientSocket)
        {
            printf("accept() error.\n");
            break;
        }
        printf("incoming client connect.\n");
        m_vecSocket.push_back(clientSocket);
        std::thread t(&LTcpServer::process, this, clientSocket);
        t.detach();
    }
    close(m_socket);
}

void LTcpServer::sendMsg(const char *buf, int len)
{
    for (size_t i = 0; i < m_vecSocket.size(); ++i)
    {
        write(m_vecSocket[i], buf, len);
    }
}

void LTcpServer::process(int socket)
{
    printf("thread started: %d.\n", gettid());
    while (1)
    {
        usleep(10 * 1000);
        memset(m_buf, 0, 4096);
        int len = read(socket, m_buf, 4096);
        if (len <= 0)
        {
            continue;
        }
        m_server->handleMessage(m_buf, len);
    }
    close(socket);
    printf("thread quited.\n");
}
