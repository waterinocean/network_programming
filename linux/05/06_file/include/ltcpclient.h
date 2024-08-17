#ifndef LTCP_CLIENT_H
#define LTCP_CLIENT_H

#include <mutex>
#include <string>

class LFileClient;

class LTcpClient
{
public:
    explicit LTcpClient(std::string ip, int port);

    void startConnect(void);
    void setClient(LFileClient* client);

    void sendMsg(const char* buf, int len);

private:
    void receiveMsg(void);

private:
    LFileClient* m_client;
    std::mutex m_mutex;
    std::string m_ip;
    int m_port;
    int m_socket;
    char m_buf[4096];
};

#endif
