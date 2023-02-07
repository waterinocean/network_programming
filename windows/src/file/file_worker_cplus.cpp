#include "file/file_worker_cplus.h"
#include <iostream>
#include <fstream>

using namespace std;

int FileWorkerCPlus::copy_file(const std::string &src, const std::string &dest)
{
    std::cout << "c plus file worker~" << std::endl;
    ifstream src_file(src, ios_base::in);
    ofstream dest_file(dest, ios_base::out);

    char c = src_file.get();
    while (src_file.good())
    {
        dest_file << c;
        c = src_file.get();
    }

    src_file.close();
    dest_file.close();
    return 0;
}
