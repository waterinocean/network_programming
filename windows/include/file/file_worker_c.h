#ifndef FILE_WORKER_C_H
#define FILE_WORKER_C_H

#include "abstract_file_worker.h"


class FileWorkerC : public AbstractFileWorker
{
public:
    int copy_file(const std::string &src, const std::string &dest);
};

#endif