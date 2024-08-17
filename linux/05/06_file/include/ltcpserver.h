#ifndef LTCP_SERVER_H
#define LTCP_SERVER_H

#include <vector>
#include <mutex>

class LFileServer;

class LTcpServer
{
public:
    explicit LTcpServer(int port);

    void setServer(LFileServer* server);
    void start(void);

    void sendMsg(const char* buf, int len);

private:
    void process(int socket);

private:
    LFileServer* m_server;
    int m_port;
    int m_socket;
    std::vector<int> m_vecSocket;
    char m_buf[4096];
};

#endif
