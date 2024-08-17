#include "lfileserver.h"
#include "lmsgbuilder.h"
#include "ltcpserver.h"
#include <algorithm>
#include <fstream>
#include "ldebug.h"
#include "lmsgparser.h"

LFileServer::LFileServer(void)
    : m_server(nullptr)
    , m_dataPath("/home/leo/code/cplusplus/01_network_programming/linux/05/06_file/bin/data/server/")
{
    m_listFile.push_back("test1");
    m_listFile.push_back("test2");
}

LFileServer::~LFileServer(void)
{
}

void LFileServer::setServer(LTcpServer *server)
{
    if (nullptr == server)
    {
        return;
    }
    m_server = server;
}

void LFileServer::startServer(void)
{
    if (nullptr == m_server)
    {
        return;
    }
    m_server->start();
}

void LFileServer::handleMessage(char *buf, int bufLen)
{
    Command cmd;
    char data[100];
    int dataLen;
    if (!LMsgParser::unpack(buf, bufLen, cmd, data, dataLen))
    {
        return;
    }
    switch (cmd)
    {
    case LCOMMAND_REQ(LCOMMAND_File):
        DBGprint("req file: %s\n", data);
        if (fileExist(std::string(data)))
        {
            DBGprint("file exist, send file data.\n");
            ackFileData(data);
        }
        else
        {
            DBGprint("file not exist.\n");
            ackFileNotExist();
        }
        break;
    default:
        break;
    }
}

bool LFileServer::fileExist(const std::string &file) const
{
    if (std::find(m_listFile.begin(), m_listFile.end(), file) != m_listFile.end())
    {
        return true;
    }
    return false;
}

void LFileServer::ackFileData(const std::string &file)
{
    char data[4096];
    int dataLen = 0;
    char name[100];
    sprintf(name, "%s%s", m_dataPath.c_str(), file.c_str());
    readFile(std::string(name), data, dataLen);
    DBGprint("file: %s, data: %d\n", file.c_str(), dataLen);
    char msg[5000];
    int msgLen = LMsgBuilder::ackFileData(msg, data, dataLen);
    m_server->sendMsg(msg, msgLen);
}

void LFileServer::ackFileNotExist(void)
{
    char msg[100];
    int len = LMsgBuilder::ackFileError(msg, "sorry, file not exists.");
    DBGprint("msg: %d\n", len);
    m_server->sendMsg(msg, len);
}

void LFileServer::readFile(const std::string &file, char *data, int &dataLen)
{
    std::ifstream stream(file, std::ios_base::in);
    if (stream)
    {
        stream.seekg(0, stream.end);
        dataLen = stream.tellg();
        stream.seekg(0, stream.beg);
        stream.read(data, dataLen);
        stream.close();
        return;
    }
    DBGprint("read file failed: %s\n", file.c_str());
    stream.close();
}
