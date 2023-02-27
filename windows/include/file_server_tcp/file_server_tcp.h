#ifndef FILE_SERVER_H
#define FILE_SERVER_H

#include "tcp_server/server_observer.h"


class FileServer: public AbstractServerObserver
{
public:
    virtual void clnt_connect(const std::string &ip, const int &port) override;
    virtual void clnt_disconnect(const std::string &ip, const int &port) override;
    virtual void receive_msg(const std::string &ip, const std::string &msg) override;
};

#endif