#include <stdio.h>
#include <string.h>
// #include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
// #include "lfileclient.h"
// #include "ltcpclient.h"
#include <condition_variable>
#include <mutex>
#include <vector>

using namespace std;

mutex g_mutexReq;
condition_variable g_conditionReq;

int main(void)
{
    printf("client");
    // LFileClient* client = new LFileClient();
    // LTcpClient* tcp = new LTcpClient("127.0.0.1", 5050);
    // tcp->setClient(client);
    // client->setClient(tcp);
    // client->startConnect();

    // std::vector<std::string> vecFile{"test1", "test2"};
    // while (1)
    // {
    //     std::unique_lock<std::mutex> lock(g_mutexReq);
    //     client->reqFile(vecFile.front());
    //     vecFile.erase(vecFile.begin());
    //     g_conditionReq.wait(lock);
    // }
    
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
