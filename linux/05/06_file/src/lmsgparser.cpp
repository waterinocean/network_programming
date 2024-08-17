#include "lmsgparser.h"
#include "ldebug.h"

bool LMsgParser::unpack(char *buf, int bufLen, Command &cmd, char *data, int& dataLen)
{
    DBGprint("input: buf[0x%x],len[%d]\n", buf, bufLen);
    int headerLen = sizeof(LHeader);
    if (bufLen < headerLen)
    {
        DBGprint("buf len < header len.\n");
        return false;
    }
    LHeader header;
    header = *((LHeader*)buf);
    if (LHEADER_VERSION != header.version)
    {
        DBGprint("header version error.\n");
        return false;
    }
    cmd = header.command;
    if (header.dataLen <= 0)
    {
        DBGprint("unpack success, command=%x, dataLen=%d.\n", header.command, header.dataLen);
        return true;
    }
    if (bufLen < headerLen + header.dataLen)
    {
        DBGprint("incomplete data, %d < %d + %d.\n", bufLen, headerLen, header.dataLen);
        return false;
    }
    dataLen = header.dataLen;
    memcpy(data, buf + headerLen, dataLen);
    DBGprint("unpack success, command=0x%08x, data=%s, dataLen=%d.\n", header.command, data, headerLen);
    return true;
}
