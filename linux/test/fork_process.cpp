#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main()
{
    pid_t p = fork();

    if (p < 0)
    {
        cout << "fork() error";
        exit(-1);
    }
    else if (p == 0)
    {
        // execlp("/usr/bin/sh", "ls", nullptr);
        cout << "child process, pid: " << getpid() << " parent pid: " << getppid() << endl;
    }
    else
    {
        cout << "parent process, pid: " << getpid() << endl;
        wait(nullptr);
        exit(0);
    }
}