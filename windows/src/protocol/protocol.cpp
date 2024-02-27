#include "protocol/protocol.h"
#include "public/pubassert.h"
#include "public/logutil.h"


int Protocol::pack(const std::string &msg, char *output)
{
    if (msg.empty())
    {
        LOG("pack msg is empty.");
        return -1;
    }
    return 0;
}

int Protocol::unpack(const char *input, char *output)
{
    return 0;
}
