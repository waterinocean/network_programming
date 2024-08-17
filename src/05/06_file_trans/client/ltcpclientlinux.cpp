#include "ltcpclientlinux.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <thread>
#include "ldebug.h"
#include "lfileclient.h"

LTcpClientLinux::LTcpClientLinux(std::string ip, int port)
    : LTcpClient(ip, port)
{
}

void LTcpClientLinux::startConnect(void)
{
    m_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (-1 == m_socket)
    {
        DBGprint("socket() error.\n");
        return;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(m_ip.c_str());
    addr.sin_port = htons(m_port);
    if (-1 == connect(m_socket, (struct sockaddr*)&addr, sizeof(addr)))
    {
        DBGprint("connect() error.\n");
        return;
    }
    std::thread t(&LTcpClientLinux::receiveMsg, this);
    t.detach();
}

void LTcpClientLinux::sendMsg(const char *buf, int len)
{
    write(m_socket, buf, len);
}

void LTcpClientLinux::receiveMsg(void)
{
    DBGprint("thread started: %d.\n", gettid());
    while (1)
    {
        usleep(10 * 1000);
        memset(m_buf, 0, 4096);
        int len = read(m_socket, m_buf, 4096);
        if (len <= 0)
        {
            continue;
        }
        m_handler->handleMessage(m_buf, len);
    }
    DBGprint("thread quited.\n");
}
