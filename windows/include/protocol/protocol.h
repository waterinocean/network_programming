//protocol for tcp package

#include <string>


const int VERSION_LENGTH                        = 0X02;
const int VERSION                               = 0X0202;
const int DATA_LENGTH                           = 0X04;
const int PACK_CRC_LENGTH                       = 0x04;
const int HEAD_LENGTH                           = VERSION_LENGTH + DATA_LENGTH + PACK_CRC_LENGTH;


class Protocol
{
public:
    int pack(const std::string& msg, char* output);
    int unpack(const char* input, char* output);

};
