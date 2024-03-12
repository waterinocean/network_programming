#include <stdio.h>
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
    FILE* srcFile = fopen(src.c_str(), "r");
    if (srcFile == nullptr)
    {
        cout << "open src file error: " << src << endl;
        exit(1);
    }
    FILE* dstFile = fopen(dst.c_str(), "w");
    if (dstFile == nullptr)
    {
        cout << "open dst file error: " << dst << endl;
        exit(1);
    }

    int maxStep = 100;
    char buf[maxStep];
    size_t readSize = 0;
    while (readSize = fread(buf, 1, maxStep, srcFile))
    {
        fwrite(buf, 1, readSize, dstFile);
    }
    fclose(srcFile);
    fclose(dstFile);
    
    return 0;
}

void errorHandling(const char* msg)
{
    cout << msg << endl;
    exit(1);
}
