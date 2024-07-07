#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdio.h>
#include <string.h>
#include <fstream>

#define LHEADER_VERSION                                     0xABBA

#define LTYPE_REQ                                           0x00010000
#define LTYPE_ACK                                           0x00020000

enum LCOMMAND
{
    LCOMMAND_Begin = 0,
    LCOMMAND_File,
    
    LCOMMAND_End
};

#define LCOMMAND_REQ(cmd)            LTYPE_REQ | cmd
#define LCOMMAND_ACK(cmd)            LTYPE_ACK | cmd

typedef unsigned int Command;

struct LHeader
{
    int version;
    int command;
    int dataLen;
};

struct LData
{
    LHeader header;
    char* data;

    LData()
    {
        header.command = 0;
        header.dataLen = 0;
        header.version = 0;
        data = nullptr;
    }
    void clear(void)
    {
        if (nullptr != data)
        {
            delete data;
            data = nullptr;
        }
        header.command = 0;
        header.dataLen = 0;
        header.version = 0;
    }
};

//pack and unpack
void pack(char* dst, int& dstLen, Command command, int dataLen = 0, char* data = nullptr)
{
    dstLen = 0;
    if (nullptr == dst)
    {
        printf("dst is nullptr.\n");
        return;
    }
    int headerLen = sizeof(LHeader);
    memset(dst, 0, headerLen + dataLen);
    //header
    LHeader header;
    header.version = LHEADER_VERSION;
    header.command = command,
    header.dataLen = dataLen;
    *((LHeader*)dst) = header;
    printf("pack: version[%x],command[%d],dataLen[%d]\n", (*(LHeader*)dst).version, (*(LHeader*)dst).command, (*(LHeader*)dst).dataLen);
    dstLen = headerLen;
    //data
    if (0 == dataLen)
    {
        printf("pack success, dstLen=%d\n", dstLen);
        return;
    }
    memcpy(dst + headerLen, data, dataLen);
    dstLen += dataLen;
    printf("pack success, dstLen=%d, dataLen=%d\n", dstLen, dataLen);
}

bool unpack(char* src, int srcLen, LData& data)
{
    int headerLen = sizeof(LHeader);
    if (srcLen < headerLen)
    {
        printf("src len < header len.\n");
        return false;
    }
    data.header = *((LHeader*)src);
    printf("unpack: version[%x],command[%d],dataLen[%d]\n", data.header.version, data.header.command, data.header.dataLen);

    if (LHEADER_VERSION != data.header.version)
    {
        printf("header version error.\n");
        return false;
    }
    if (data.header.dataLen <= 0)
    {
        printf("unpack success, dataLen=%d.\n", data.header.dataLen);
        return true;
    }
    if (srcLen < headerLen + data.header.dataLen)
    {
        printf("incomplete data, %d < %d + %d.\n", srcLen, headerLen, data.header.dataLen);
        return false;
    }
    data.data = new char[data.header.dataLen];
    memcpy(data.data, src + headerLen, data.header.dataLen);
    printf("unpack success, dataLen=%d.\n", data.header.dataLen);
    return true;
}

//common function
void reqFile(char* buf, int& len)
{
    if (nullptr == buf)
    {
        return;
    }
    pack(buf, len, LCOMMAND_REQ(LCOMMAND_File));
}

void ackFile(char* buf, int& bufLen, const char* file)
{
    //read file
    std::ifstream stream(file, std::ios_base::in);
    if (!stream.is_open())
    {
        printf("open file error:%s\n", file);
        return;
    }
    stream.seekg(0, stream.end);
    int fileLen = stream.tellg();
    stream.seekg(0, stream.beg);
    char fileBuf[4096];
    stream.read(fileBuf, fileLen);
    //pack
    pack(buf, bufLen, LCOMMAND_ACK(LCOMMAND_File), fileLen, fileBuf);
}

#endif
