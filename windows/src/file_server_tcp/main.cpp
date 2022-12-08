#include "file/file_worker.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    string src_file, dest_file;

    cout  << "please input file name you want to copy." << endl;
    getline(cin, src_file);

    cout  << "please input file name you want to past." << endl;
    getline(cin, dest_file);

    FileWorker file_worker = FileWorker("c");
    file_worker.copy_file(src_file, dest_file);
    
    return 0;
}