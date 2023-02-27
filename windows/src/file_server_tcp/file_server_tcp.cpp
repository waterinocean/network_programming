#include "file_server_tcp/file_server_tcp.h"
#include <iostream>

using namespace std;

void FileServer::clnt_connect(const std::string &ip, const int &port)
{
    cout << "client connect, ip: " << ip << " port: " << port << endl;
}

void FileServer::clnt_disconnect(const std::string &ip, const int &port)
{
    cout << "client disconnect, ip: " << ip << " port: " << port << endl;
}

void FileServer::receive_msg(const std::string &ip, const std::string &msg)
{
    cout << "receive message from ip: " << ip << " msg content: " << msg << endl;
}
