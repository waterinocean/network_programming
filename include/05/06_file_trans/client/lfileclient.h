#ifndef LFILE_CLIENT_H
#define LFILE_CLIENT_H

#include <string>
#include "protocol.h"

class LTcpClient;

class LFileClient
{
public:
    explicit LFileClient(void);
    ~LFileClient(void);
  
    void setClient(LTcpClient* client);
    void startConnect(void);

    void reqFile(const std::string& name);
    void handleMessage(char* buf, int len);

private:
    void handleFileAck(Command cmd, char* data, int dataLen);
    void saveFile(const std::string& name, char* data, int dataLen);

private:
    LTcpClient* m_client;
    std::string m_fileName;
    std::string m_dataPath;
};

#endif
