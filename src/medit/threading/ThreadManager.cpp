#include "ThreadManager.hpp"

namespace Medit
{
namespace Threading
{

ThreadManager::ThreadManager()
{
}

ThreadManager::~ThreadManager()
{
    removeAll();
}

ThreadManager::ThreadPtr ThreadManager::createThread(IWorker *worker)
{
    Thread::Allocator alloc;

    ThreadPtr thread = alloc.allocate(1);
    alloc.construct(thread, worker);

    threads.push_back(thread);

    return thread;
}

void ThreadManager::removeAll()
{
    Thread::Allocator alloc;

    for (ThreadList::iterator pos = threads.begin(); pos != threads.end(); ++pos)
    {
        ThreadPtr thread = *pos;

        if (!thread->isJoined())
        {
            thread->join();
        }

        alloc.destroy(thread);
        alloc.deallocate(thread, 1);
    }

    threads.clear();
}

void ThreadManager::removeThread(Thread *thread)
{
    // search for iterator
    ThreadList::iterator pos = find(threads.begin(), threads.end(), thread);

    if (pos != threads.end())
    {
        // thread was found
        thread->join();

        Thread::Allocator alloc;
        alloc.destroy(thread);
        alloc.deallocate(thread, 1);

        threads.erase(pos);
    }
}

ThreadManager::ThreadList ThreadManager::getThreads() const
{
    return threads;
}

} // namespace Threading
} // namespace Medit
