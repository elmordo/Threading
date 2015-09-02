#ifndef MEDIT_THREADING_LINUX_THREAD_HPP
#define MEDIT_THREADING_LINUX_THREAD_HPP

#include <pthread.h>

#include "../IWorker.hpp"


namespace Medit
{
namespace Threading
{
namespace Linux
{


class Thread
{

    /**
     * @brief pointer to current thread
     */
    pthread_t *threadId;

public:

    /**
     * @brief create empty instance
     */
    Thread();

    /**
     * @brief copytor
     * @param original instance with original data
     */
    Thread(const Thread &original);

    /**
     * @brief destructor
     */
    virtual ~Thread();

    /**
     * @brief return true if thread is running
     * @return
     */
    bool isAlive() const;

    /**
     * @brief start new thread with given worker
     * @param worker worker instance to run
     */
    void start(IWorker *worker);

    /**
     * @brief join running thread
     */
    void join();

    /**
     * @brief force terminate running thread
     */
    void terminate();

    /**
     * @brief assign operator
     * @param original instance with original data
     * @return reference to self
     */
    Thread *operator =(const Thread &original);

}


}
}
}


#endif
