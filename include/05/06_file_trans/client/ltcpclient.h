#ifndef LTCP_CLIENT_H
#define LTCP_CLIENT_H

#include <string>

class LFileClient;

class LTcpClient
{
public:
    explicit LTcpClient(std::string ip, int port);

    void setHandler(LFileClient* handler);

    virtual void startConnect(void) = 0;
    virtual void sendMsg(const char* buf, int len) = 0;

protected:
    LFileClient* m_handler;
    std::string m_ip;
    int m_port;
    int m_socket;
    char m_buf[4096];
};

#endif
