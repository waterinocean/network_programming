#ifndef ABSTRACT_FILE_WORKER_H
#define ABSTRACT_FILE_WORKER_H

#include <string>

class AbstractFileWorker
{
public:
    virtual int copy_file(const std::string &src, const std::string &dest) = 0;
};

#endif