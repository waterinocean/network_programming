
#include <string>
#include <vector>
#include <winsock2.h>


#define BUFF_LEN   (10 * 1024 * 1024)

class TcpClient
{
public:
    explicit TcpClient(std::string srv_ip, int port);
    ~TcpClient();

    void startConnect(void);
    void startDisconnect(void);
    void sendMessage(std::string msg);

private:
    void init(void);
    bool initSocket(void);
    bool initBuffer(void);
    void recvMessage(void);

private:
    std::string     m_serverIp;
    int             m_port;
    SOCKADDR_IN     m_serverAddr;
    bool            m_inited;
    bool            m_connected;

    SOCKET          m_socket;
    char*           m_buf;
};
