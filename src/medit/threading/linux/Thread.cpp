#include "Thread.hpp"

namespace Medit
{
namespace Threading
{
namespace Linux
{

void *runner(void *arg)
{
    // retype argument to worker and run logic
    IWorker *worker = (IWorker*) arg;

    worker->doAction();
}

Thread::Thread()
{
    worker = 0x0;
    threadId = 0;
}

Thread::Thread(const Thread &original)
{
    worker = original.worker;
    threadId = original.threadId;
}

Thread::~Thread()
{
    allocator<IWorker> alloc;
    alloc.destroy(worker);
    alloc.deallocate(worker);
}

void Thread::start()
{
    if (!worker)
    {
        MEDIT_THROW(ThreadException, "Worker is not set", ThreadException::WORKER_NOT_SET);
    }

    pthread_create(&threadId, NULL, runner, worker);
}

}
}
}
