#include "lmsgbuilder.h"

int LMsgBuilder::reqFile(char *buf, const char* name)
{
    int len = sizeof(name);
    return pack(buf, LCOMMAND_REQ(LCOMMAND_File), name, len);
}

int LMsgBuilder::ackFileError(char *buf, const char *err)
{
    int len = sizeof(err);
    return pack(buf, LCOMMAND_ACK(LCOMMAND_File) | LTYPE_FAILED, err, len);
}

int LMsgBuilder::ackFileData(char *buf, const char *file, int fileLen)
{
    return pack(buf, LCOMMAND_ACK(LCOMMAND_File) | LTYPE_SUCCESS, file, fileLen);
}

int LMsgBuilder::pack(char *buf, Command cmd)
{
    if (nullptr == buf)
    {
        return -1;
    }

    int headerLen = sizeof(LHeader);
    memset(buf, 0, headerLen);
    LHeader header;
    header.version = LHEADER_VERSION;
    header.dataLen = 0;
    header.command = cmd;
    *((LHeader*)buf) = header;
    return headerLen;
}

int LMsgBuilder::pack(char *buf, Command cmd, const char *data, int dataLen)
{
    if (nullptr == buf)
    {
        return -1;
    }

    int headerLen = sizeof(LHeader);
    memset(buf, 0, headerLen + dataLen);
    LHeader header;
    header.version = LHEADER_VERSION;
    header.dataLen = dataLen;
    header.command = cmd;
    *((LHeader*)buf) = header;
    memcpy(buf + headerLen, data, dataLen);
    return headerLen + dataLen;
}
