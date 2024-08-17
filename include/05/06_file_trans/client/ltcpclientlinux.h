#ifndef LTCP_CLIENT_LINUX_H
#define LTCP_CLIENT_LINUX_H

#include <string>
#include "ltcpclient.h"

class LTcpClientLinux : public LTcpClient
{
public:
    explicit LTcpClientLinux(std::string ip, int port);

    virtual void startConnect(void) override;
    virtual void sendMsg(const char* buf, int len) override;

private:
    void receiveMsg(void);

};

#endif
