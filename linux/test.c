#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char msg[1024];
    memset(msg, 0, 1024);

    int val = 4;
    msg[0] = val;

    int index = 4;
    for (int i = 0; i< 4; i++)
    {
        int tmp_val = i + 1;
        msg[index] = tmp_val;
        index += 4;
    }
    msg[index] = '\0';
    printf("realy %s", msg);
    return 0;
}