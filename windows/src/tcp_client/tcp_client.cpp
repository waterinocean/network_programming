#include "tcp_client/tcp_client.h"
#include <iostream>
#include <thread>
#include "public/pubassert.h"
#include "public/logutil.h"


using namespace std;


TcpClient::TcpClient(std::string srv_ip, int port)
    : m_serverIp(srv_ip)
    , m_port(port)
    , m_inited(false)
    , m_connected(false)
    , m_buf(nullptr)
{
    init();
}

TcpClient::~TcpClient()
{
    startDisconnect();
}

void TcpClient::startConnect(void)
{
    if (!m_inited)
    {
        LOG("init failed.");
        return;
    }
    if (m_connected)
    {
        LOG("already connected.");
        return;
    }

    if (connect(m_socket, (SOCKADDR*)&m_serverAddr, sizeof(m_serverAddr)) == SOCKET_ERROR)
    {
        LOG("connect() error!");
    }
    m_connected =  true;

    thread thread_recv(&TcpClient::recvMessage, this);
    thread_recv.detach();
}

void TcpClient::startDisconnect(void)
{
    if (!m_connected)
    {
        LOG("not connected.");
        return;
    }
    
    m_connected = false;
}

void TcpClient::sendMessage(std::string msg)
{
    int sendLen = 0;
    if ((sendLen = send(m_socket, msg.c_str(), sizeof(msg), 0)) == -1)
    {
        LOG("send() error!");
    }
    cout << "send msg: " << msg << endl;
}

void TcpClient::init()
{
    if (!initSocket())
    {
        return;
    }
    if (!initBuffer())
    {
        return;
    }
    m_inited = true;
}

bool TcpClient::initSocket(void)
{
    WSADATA wasData;
    if (WSAStartup(MAKEWORD(2, 2), &wasData) != 0)
    {
        LOG("WSAStartup() error!");
        return false;
    }

    m_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (m_socket == INVALID_SOCKET)
    {
        LOG("socket create failed!");
        return false;
    }

    memset(&m_serverAddr, 0, sizeof(m_serverAddr));
    m_serverAddr.sin_family = AF_INET;
    m_serverAddr.sin_addr.S_un.S_addr = inet_addr(m_serverIp.c_str());
    m_serverAddr.sin_port = htons(m_port);

    return true;
}

bool TcpClient::initBuffer(void)
{
    m_buf = new char[BUFF_LEN];
    ASSERT_POINTER_R(m_buf, false);
    return true;
}

void TcpClient::recvMessage(void)
{
    LOG("recv msg started...");
    int readLen = 0;
    while (1)
    {
        if (!m_connected)
        {
            LOG("start disconnect, close socket begin.")
            break;
        }
        memset(m_buf, 0, BUFF_LEN);
        if ((readLen = recv(m_socket, m_buf, BUFF_LEN, 0)) == -1)
        {
            LOG("recv() error! close socket");
            break;
        }
        LOG("recv msg: ");
        LOG(m_buf);
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << "recv finished...";

    int ret = closesocket(m_socket);
    if (ret != 0)
    {
        LOG("close socket error");
    }
    LOG("client closed...");
    m_connected = false;
}
