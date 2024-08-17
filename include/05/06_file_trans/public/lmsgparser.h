#ifndef LMSG_PARSER_H
#define LMSG_PARSER_H

#include "protocol.h"

class LMsgParser
{
public:
    static bool unpack(char* buf, int bufLen, Command& cmd, char* data, int& dataLen);
};

#endif
