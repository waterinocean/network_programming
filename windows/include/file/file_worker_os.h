#ifndef FILE_WORKER_OS_H
#define FILE_WORKER_OS_H

#include "abstract_file_worker.h"


class FileWorkerOS : public AbstractFileWorker
{
public:
    int copy_file(const std::string &src, const std::string &dest);
};

#endif