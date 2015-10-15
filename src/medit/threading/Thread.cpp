#include "Thread.hpp"

namespace Medit
{
namespace Threading
{

void workerStarter(IWorker *worker)
{
    worker->doAction();
}


IWorker *Thread::getWorker() const
{
    return worker;
}

void Thread::setWorker(IWorker *value)
{
    // test if worker is in process
    if (internalThread.joinable())
    {
        MEDIT_THROW(ThreadException, "Internal thread is running",
                    ThreadException::THREAD_IS_RUNNING);
    }

    worker = value;
}
Thread::Thread()
{
    worker = 0x0;
}

Thread::Thread(IWorker *worker)
{
    this->worker = worker;
}

Thread::~Thread()
{
    // join thread before deleting instance
    join();

    // destroy worker if set
    if (worker)
    {
        IWorker::Allocator alloc;
        alloc.destroy(worker);
        alloc.deallocate(worker, 1);
    }
}

Thread::threadId Thread::getId() const
{
    return internalThread.get_id();
}

void Thread::join()
{
    if (internalThread.joinable())
    {
        internalThread.join();
    }
}

void Thread::start()
{
    internalThread = thread(workerStarter, worker);
}

bool Thread::isJoined() const
{
    return internalThread.joinable();
}

} // namespace Threading
} // namespace Medit

