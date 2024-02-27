
#include "tcp_client/tcp_client.h"
#include "file_client_tcp/file_client_tcp.h"

#include <iostream>
#include <thread>

using namespace std;

int main()
{
    TcpClient tcpClient("127.0.0.1", 5050);
    tcpClient.startConnect();

    string msg;
    while (1)
    {
        cout << "please input something..." << endl;
        getline(cin, msg);
        if (msg == "q")
        {
            break;
        }
        tcpClient.sendMessage(msg.c_str());
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    return 0;
}
