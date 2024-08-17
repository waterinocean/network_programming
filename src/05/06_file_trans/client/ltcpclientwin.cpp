#include "ltcpclientwin.h"
#include "ldebug.h"
#include <string.h>
#include <thread>
#include "lfileclient.h"

LTcpClientWin::LTcpClientWin(std::string ip, int port)
    : LTcpClient(ip, port)
{
}

LTcpClientWin::~LTcpClientWin(void)
{
    closesocket(m_socket);
    WSACleanup();
}

void LTcpClientWin::startConnect(void)
{
    WSADATA wsaData;
    if (0 != WSAStartup(MAKEWORD(2, 2), &wsaData))
    {
        DBGprint("WSAStartup() error!\n");
        return;
    }

    m_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (INVALID_SOCKET == m_socket)
    {
        DBGprint("socket() error!\n");
        return;
    }

    SOCKADDR_IN serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.S_un.S_addr = inet_addr(m_ip.c_str());
    serverAddr.sin_port = htons(m_port);

    if (SOCKET_ERROR == connect(m_socket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)))
    {
        DBGprint("connect() error!\n");
        return;
    }

    DBGprint("connect success: %d\n", m_port);
    std::thread t(&LTcpClientWin::receiveMsg, this);
    t.detach();
}

void LTcpClientWin::sendMsg(const char *buf, int len)
{
}

void LTcpClientWin::receiveMsg(void)
{
    while (1)
    {
        int recvLen = recv(m_socket, m_buf, 100, 0);
        if (recvLen > 0)
        {
            m_handler->handleMessage(m_buf, recvLen);
        }
    }
}
