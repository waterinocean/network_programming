#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024
void error_handling(char* msg)
{
    printf("%s \n", msg);
    exit(1);
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <port> \n", argv[0]);
        exit(1);
    }

    //define some variable
    int sock_serv, sock_clnt;
    struct sockaddr_in serv_addr, clnt_addr;
    int clnt_addr_size = sizeof(clnt_addr);
    char msg[BUF_SIZE];

    //init socket object
    sock_serv = socket(PF_INET, SOCK_STREAM, 0);
    if (sock_serv == -1)
        error_handling("socket() error.");

    //init socket addr
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(argv[1]);

    //bind
    if (bind(sock_serv, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error.");
    

    //listen
    if (listen(sock_serv, 5) == -1)
        error_handling("listen() error.");

    //accept
    if ((sock_clnt = accept(sock_serv, (struct sockaddr*)&clnt_addr, &clnt_addr_size)) == -1)
        error_handling("accept() error.");
        
    //while loop for op
    while (1)
    {
        /* code */
    }
    
    //close socket
    close(sock_serv);
    return 0;
}