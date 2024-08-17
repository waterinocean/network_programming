#include "lfileclient.h"
#include "ltcpclient.h"
#include "lmsgbuilder.h"
#include "lmsgparser.h"
#include <fstream>
#include "ldebug.h"

LFileClient::LFileClient(void)
    : m_client(nullptr)
    , m_dataPath("/home/leo/code/cplusplus/01_network_programming/linux/05/06_file/bin/data/client/")
{
}

LFileClient::~LFileClient(void)
{
}

void LFileClient::setClient(LTcpClient *client)
{
    if (nullptr == client)
    {
        return;
    }
    m_client = client;
    m_client->setClient(this);
}

void LFileClient::startConnect(void)
{
    if (nullptr == m_client)
    {
        return;
    }
    m_client->startConnect();
}

void LFileClient::handleMessage(char *buf, int len)
{
    Command cmd;
    char data[100];
    int dataLen = 0;
    if (!LMsgParser::unpack(buf, len, cmd, data, dataLen))
    {
        return;
    }
    switch (cmd & 0xFFFF)
    {
    case LCOMMAND_File:
        DBGprint("ack file\n");
        handleFileAck(cmd, data, dataLen);
        break;
    default:
        break;
    }
}

void LFileClient::reqFile(const std::string &name)
{
    if (nullptr == m_client)
    {
        return;
    }
    m_fileName = name;
    char buf[100];
    int len = LMsgBuilder::reqFile(buf, name.c_str());
    m_client->sendMsg(buf, len);
}

void LFileClient::handleFileAck(Command cmd, char *data, int dataLen)
{
    if (LTYPE_SUCCESS == (cmd & 0x00FF0000))
    {
        DBGprint("receive file success.\n");
        char file[100];
        sprintf(file, "%s%s", m_dataPath.c_str(), m_fileName.c_str());
        saveFile(std::string(file), data, dataLen);
    }
    else
    {
        DBGprint("receive file failed: %s.\n", data);
    }
}

void LFileClient::saveFile(const std::string &name, char *data, int dataLen)
{
    std::ofstream stream(name, std::ios_base::out);
    stream.seekp(0, stream.beg);
    stream.write(data, dataLen);
}
