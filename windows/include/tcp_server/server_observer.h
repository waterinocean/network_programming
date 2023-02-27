#ifndef SERVER_OBSERVER_H
#define SERVER_OBSERVER_H

#include <string>

class AbstractServerObserver
{
public:
    virtual void clnt_connect(const std::string &ip, const int &port) = 0;
    virtual void clnt_disconnect(const std::string &ip, const int &port) = 0;
    virtual void receive_msg(const std::string &ip, const std::string &msg) = 0;
};

#endif