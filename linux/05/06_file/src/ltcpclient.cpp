#include "ltcpclient.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <thread>
#include "ldebug.h"
#include "lfileclient.h"

LTcpClient::LTcpClient(std::string ip, int port)
    : m_client(nullptr)
    , m_ip(ip)
    , m_port(port)
    , m_socket(0)
    , m_buf({0})
{
}

void LTcpClient::startConnect(void)
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
    std::thread t(&LTcpClient::receiveMsg, this);
    t.detach();
}

void LTcpClient::setClient(LFileClient* client)
{
    m_client = client;
}

void LTcpClient::sendMsg(const char *buf, int len)
{
    // std::lock_guard<std::mutex> mutex_locker(m_mutex);
    write(m_socket, buf, len);
}

void LTcpClient::receiveMsg(void)
{
    DBGprint("thread started: %d.\n", gettid());
    while (1)
    {
        usleep(10 * 1000);
        // m_mutex.lock();
        memset(m_buf, 0, 4096);
        int len = read(m_socket, m_buf, 4096);
        if (len <= 0)
        {
            // m_mutex.unlock();
            continue;
        }
        m_client->handleMessage(m_buf, len);
        // m_mutex.unlock();
    }
    DBGprint("thread quited.\n");
}
