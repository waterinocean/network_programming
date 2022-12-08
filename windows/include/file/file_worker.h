#ifndef FILE_WORKER_H
#define FILE_WORKER_H

#include <string>
#include <memory>

class AbstractFileWorker;
class FileWorker
{
public:
    explicit FileWorker(const std::string &worker_name);

    int copy_file(const std::string &src, const std::string &dest);

private:
    std::shared_ptr<AbstractFileWorker> file_worker = {};
};

#endif