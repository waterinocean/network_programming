
#include "ltcpclient.h"

LTcpClient::LTcpClient(std::string ip, int port)
    : m_ip(ip)
    , m_port(port)
{
}

void LTcpClient::setHandler(LFileClient *handler)
{
    if (nullptr == handler)
    {
        return;
    }
    m_handler = handler;
}
