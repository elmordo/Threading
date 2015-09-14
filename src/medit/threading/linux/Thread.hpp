#ifndef MEDIT_THREADING_LINUX_THREAD_HPP
#define MEDIT_THREADING_LINUX_THREAD_HPP

#include <pthread.h>

#include "../IWorker.hpp"
#include "../ISignal.hpp"


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

    /**
     * @brief worker instance running in thread
     */
    IWorker *worker;

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
     * @brief start new thread with worker
     * @param worker worker instance to run
     */
    void start();

    /**
     * @brief join running thread
     */
    void join();

    /**
     * @brief force terminate running thread
     */
    void terminate();

    /**
     * @brief propagate signal into running worker
     *      if no worker running, nothing happend
     * @param signal signal instance to propagate
     */
    void sendSignal(const ISignal &signal);

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
