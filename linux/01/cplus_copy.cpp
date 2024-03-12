#include <fstream>
#include <iostream>

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
    ifstream srcFile(src);
    ofstream dstFile(dst);
    if (!srcFile.is_open())
    {
        cout << "open src file error: " << src << endl;
        exit(1);
    }
    if (!dstFile.is_open())
    {
        cout << "open dst file error: " << dst << endl;
        exit(1);
    }

    char buf[100];
    while (srcFile.read(buf, 1))
    {
        dstFile.write(buf, 1);
    }
    srcFile.close();
    dstFile.close();
    return 0;
}

void errorHandling(const char* msg)
{
    cout << msg << endl;
    exit(1);
}
