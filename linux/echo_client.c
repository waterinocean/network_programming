#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char* msg);

int main(int argc, char* argv[])
{
    int sock;
    char msg[BUF_SIZE];
    int str_len;
    struct sockaddr_in serv_addr;

    if (argc != 3)
    {
        printf("Usage: %s <IP> <port> \n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handling("socket() error.");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error.");
    else
        puts("Connected......");

    while (1)
    {
        fputs("Input message(Q to quit): ", stdout);
        fgets(msg, BUF_SIZE, stdin);

        if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n"))
            break;
        
        str_len = write(sock, msg, strlen(msg));
        int rec_len = 0;
        while (rec_len < str_len)
        {
            int rec_cnt = read(sock, msg, BUF_SIZE-1);
            if (rec_cnt == -1)
                error_handling("read() error.");
            
            rec_len += rec_cnt;
        }
        msg[rec_len] = 0;
        printf("Message from server: %s", msg);
    }
    close(sock);
    return 0;
}

void error_handling(char* msg)
{
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}