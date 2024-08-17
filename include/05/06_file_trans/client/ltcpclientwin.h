#ifndef LTCP_CLIENT_WIN_H
#define LTCP_CLIENT_WIN_H

#include "ltcpclient.h"
#include <winsock2.h>

class LTcpClientWin : public LTcpClient
{
public:
    explicit LTcpClientWin(std::string ip, int port);
    ~LTcpClientWin(void);

    virtual void startConnect(void) override;
    virtual void sendMsg(const char* buf, int len) override;

private:
    void receiveMsg(void);

private:
    SOCKET m_socket;
};

#endif
