#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

void errorHandling(const char* msg);
int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " <src> <dst>" << endl;
        exit(1);
    }

    string src = argv[1];
    string dst = argv[2];
    int srcFile = open(src.c_str(), O_RDONLY);
    if (srcFile <= 0)
    {
        cout << "open src file error: " << src << endl;
        exit(1);
    }
    int dstFile = open(dst.c_str(), O_WRONLY | O_CREAT);
    if (dstFile <= 0)
    {
        cout << "open dst file error: " << dst << endl;
        exit(1);
    }

    int maxStep = 100;
    char buf[maxStep];
    int readSize = 0;
    while (readSize = read(srcFile, buf, 100))
    {
        write(dstFile, buf, readSize);
    }
    close(srcFile);
    close(dstFile);
    
    return 0;
}

void errorHandling(const char* msg)
{
    cout << msg << endl;
    exit(1);
}
