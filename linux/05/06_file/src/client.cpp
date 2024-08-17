#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include <fstream>
#include <string>
#include "lfileclient.h"
#include "ltcpclient.h"

using namespace std;

int main(void)
{

    LFileClient* client = new LFileClient();
    LTcpClient* tcp = new LTcpClient("127.0.0.1", 5050);
    tcp->setClient(client);
    client->setClient(tcp);
    client->startConnect();

    while (1)
    {
        client->reqFile(std::string("test1"));
        usleep(6 * 1000 * 1000);
    }
    
    // while (1)
    // {
    //     printf("Please input the file name you want:\n");
    //     char name[100];
    //     scanf("%s", name);
    //     client->reqFile(std::string(name));
    //     usleep(100 * 1000);
    // }
    return 0;
}
