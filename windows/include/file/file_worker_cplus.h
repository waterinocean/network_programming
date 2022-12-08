#ifndef FILE_WORKER_C_PLUS_H
#define FILE_WORKER_C_PLUS_H

#include "abstract_file_worker.h"

class FileWorkerCPlus : public AbstractFileWorker
{
public:
    virtual int copy_file(const std::string &src, const std::string &dest);
};


#endif