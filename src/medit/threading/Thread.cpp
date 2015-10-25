#include "Thread.hpp"

namespace Medit
{
namespace Threading
{

#ifdef TEST
size_t Thread::killCounter = 0;
#endif

void workerStarter(IWorker *worker)
{
    if (worker == NULL)
    {
        MEDIT_THROW(ThreadException, "Worker is not set", ThreadException::WORKER_IS_NOT_SET);
    }

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

Thread::Thread(const Thread &)
{
    MEDIT_THROW(ThreadException, "Thread can not be coppied", ThreadException::THREAD_CAN_NOT_BE_COPIED);
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

    // increase kill counter if this is test target
#ifdef TEST
    ++killCounter;
#endif
}

Thread::ThreadId Thread::getId() const
{
    return internalThread.get_id();
}

void Thread::join()
{
    if (internalThread.joinable() && worker)
    {
        // set kill signal
        Signal sig(IWorker::SHUT_DOWN);
        worker->sendSignal(&sig);

        internalThread.join();
    }
}

void Thread::start()
{
    if (!worker)
    {
        MEDIT_THROW(ThreadException, "Worker is not set", ThreadException::WORKER_IS_NOT_SET);
    }

    if (!isJoined())
    {
        MEDIT_THROW(ThreadException, "Thread is running", ThreadException::THREAD_IS_RUNNING);
    }

    internalThread = thread(workerStarter, worker);
}

bool Thread::isJoined() const
{
    return !internalThread.joinable();
}

Thread &Thread::operator =(const Thread &)
{
    MEDIT_THROW(ThreadException, "Thread can not be coppied", ThreadException::THREAD_CAN_NOT_BE_COPIED);
}

} // namespace Threading
} // namespace Medit
