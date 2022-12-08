#include "file/file_worker.h"
#include "file/abstract_file_worker.h"
#include "file/file_worker_factory.h"

using namespace std;

FileWorker::FileWorker(const std::string &worker_name)
{
    this->file_worker = FileWorkerFactory().create(worker_name);
}

// FileWorker::~FileWorker()
// {
// }

int FileWorker::copy_file(const std::string &src, const std::string &dest)
{
    return this->file_worker->copy_file(src, dest);
}
