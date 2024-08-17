#ifndef LMSG_BUILDER_H
#define LMSG_BUILDER_H

#include "protocol.h"

class LMsgBuilder
{
public:
    static int reqFile(char* buf, const char* name);
    static int ackFileError(char* buf, const char* err);
    static int ackFileData(char* buf, const char* file, int fileLen);

private:
    static int pack(char* buf, Command cmd);
    static int pack(char* buf, Command cmd, const char* data, int dataLen);
};

#endif
