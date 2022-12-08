#include "file/file_worker_factory.h"
#include "file/abstract_file_worker.h"
#include "file/file_worker_c.h"
#include "file/file_worker_cplus.h"
#include "file/file_worker_os.h"

using namespace std;

std::shared_ptr<AbstractFileWorker> FileWorkerFactory::create(const std::string &worker_name)
{
    if (worker_name == "c")
        return make_shared<FileWorkerC>(FileWorkerC());
    else if (worker_name == "c++")
        return make_shared<FileWorkerCPlus>(FileWorkerCPlus());
    else if (worker_name == "os")
        return make_shared<FileWorkerOS>(FileWorkerOS());
}
