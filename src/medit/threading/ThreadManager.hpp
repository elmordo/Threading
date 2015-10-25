#ifndef MEDIT_THREADING_THREADMANAGER_HPP
#define MEDIT_THREADING_THREADMANAGER_HPP

#include <algorithm>
#include <list>

#include "Thread.hpp"

namespace Medit
{
namespace Threading
{

class ThreadManager
{
public:

    typedef list<Thread *> ThreadList;

    typedef Thread* ThreadPtr;

private:

    /**
     * @brief set of managed threads
     */
    ThreadList threads;

public:

    /**
     * @brief create empty instance
     */
    ThreadManager();

    /**
     * @brief kill running threads and destroy instance
     */
    virtual ~ThreadManager();

    /**
     * @brief create thread and put it into manager
     * @param worker optional worker to set
     * @return new thread instance
     */
    ThreadPtr createThread(IWorker *worker=NULL);

    /**
     * @brief remove all threads from manager. Running threads are killed
     */
    void removeAll();

    /**
     * @brief remove thread from manager. If thread is running, kills it
     * @param thread pointer ti thread to remove
     */
    void removeThread(Thread *thread);

    /**
     * @brief managed threads accessor
     * @return list of thread
     */
    ThreadList getThreads() const;

};

} // namespace Threading
} // namespace Medit

#endif // MEDIT_THREADING_THREADMANAGER_HPP
