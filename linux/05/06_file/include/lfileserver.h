#ifndef LFILESERVER_H
#define LFILESERVER_H

#include <string>
#include <list>

class LTcpServer;

class LFileServer
{
public:
    explicit LFileServer(void);
    ~LFileServer(void);

    void setServer(LTcpServer* server);
    void startServer(void);

    void handleMessage(char* buf, int bufLen);

private:
    bool fileExist(const std::string& file) const;
    void ackFileData(const std::string& file);
    void ackFileNotExist(void);
    void readFile(const std::string& file, char* data, int& dataLen);

private:
    LTcpServer* m_server;
    std::list<std::string> m_listFile;
    std::string m_dataPath;
};

#endif
