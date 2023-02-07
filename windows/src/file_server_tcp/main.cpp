#include "file/file_worker.h"
#include "tcp_server/tcp_server.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "main thread is running, thread id is: " << std::this_thread::get_id() << endl;
    //parse input, get server port

    //start server
    TcpServer tcp_server = TcpServer(5050);
    tcp_server.start();

    // special pause

    std::this_thread::sleep_for(std::chrono::seconds(1 * 60));

    //get received msg, decide what to do

    //if need a file, read file and transfer data stream
    
    //stop server

    cout << "main thread finishing, thread id is: " << std::this_thread::get_id() << endl;

    return 0;
}