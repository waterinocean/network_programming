#ifndef FILE_WORKER_FACTORY_H
#define FILE_WORKER_FACTORY_H

#include <string>
#include <memory>

class AbstractFileWorker;
class FileWorkerFactory
{
public:
    std::shared_ptr<AbstractFileWorker> create(const std::string &worker_name);
};

#endif