#include "file/file_worker.h"
#include "tcp_server/tcp_server.h"
#include "file_server_tcp/file_server_tcp.h"

#include <iostream>

using namespace std;

int main()
{
    //set up file server - tcp
    std::shared_ptr<FileServer> file_server = 
    std::make_shared<FileServer>(FileServer());

    //start tcp server, the event loop
    TcpServer tcp_server = TcpServer(5050);
    tcp_server.set_observer(file_server);
    tcp_server.start();

    return 0;
}