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
    int clnt_sock;
    struct sockaddr_in serv_addr;
    char* msg[BUF_SIZE];

    if (argc != 3)
    {
        printf("Usage: %s <ip> <port> \n", argv[0]);
        exit(1);
    }

    //socket init
    clnt_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (clnt_sock == -1)
        error_handling("socket() error.");

    //server addr set
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    //connect to server
    if (connect(clnt_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error.");

    while (1)
    {
        memset(msg, 0, BUF_SIZE);
        //ask question and get result
        printf("please input the opreate number count(q to quit): \n");
        char op_str;
        scanf("%c", &op_str);
        if ('q' == op_str || 'Q' == op_str)
            break;
        int op_cnt = op_str;
        if (op_cnt == 0)
            error_handling("the input is error!");

        int index = 0;    
        *(int64_t*)msg = op_cnt;
        index += 4;
        for (int i = 0; i < op_cnt; i++)
        {
            printf("please input the number: \n");
            int op_value =  0;
            scanf("%d", &op_value);
            *(int64_t*)(msg + index) = op_value;
            index += 4;
        }
        printf("please input an operate: + - * /");
        char op;
        scanf("%c", &op);
        *(char*)(msg + index) = op;
        index += 1;
        *(char*)(msg + index) = 'e';
        index += 1;

        //send msg and recv answer
        if (write(clnt_sock, msg, index) == -1)
            error_handling("write() error.");
        int recv_len = 0;
        if ((recv_len = read(clnt_sock, msg, 1024)) == -1)
            error_handling("read() error.");
        if (recv_len < 4)
            error_handling("read content error.");
            
        int res = *(int64_t*)msg;
        printf("the answer is : %d", res);
    }

    close(clnt_sock);
    return 0;
}

void error_handling(char* msg)
{
    printf("%s \n", msg);
    exit(1);
}
