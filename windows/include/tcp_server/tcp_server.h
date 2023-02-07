#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <winsock2.h>

struct SocketInfo
{
    SocketInfo(SOCKET socket, SOCKADDR_IN socket_addr, int sock_addr_size):
    socket(socket),socket_addr(socket_addr),sock_addr_size(sock_addr_size) {}
    
    SOCKET socket;
    SOCKADDR_IN socket_addr;
    int sock_addr_size;
};

class TcpServer
{
public:
    explicit TcpServer(const int &srv_port = 5050);
    ~TcpServer();

public:
    //start listen
    void start();

private:
    void init_socket_use();
    void create_socket();
    void socket_bind_port();
    void accept_clnt_sock();
    void read_msg(std::shared_ptr<SocketInfo> sock_info);
    void send_msg(const std::string &ip, const std::string &msg);
    void close_socket();
    void clear_up();

    void err_handling(const std::string &err_msg);

private:
    WSADATA wsa_data;

    SOCKET srv_socket;
    SOCKADDR_IN srv_addr;
    int srv_port;

    std::vector<std::shared_ptr<SocketInfo>> clnt_sockets = {};
};

#endif
