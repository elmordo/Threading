#ifndef MEDIT_THREADING_LINUX_THREAD_HPP
#define MEDIT_THREADING_LINUX_THREAD_HPP

#include <pthread.h>

namespace Medit
{
namespace Threading
{
namespace Linux
{


class Thread
{

    /**
     * @brief current thread
     */
    pthread_t threadId;

public:

    Thread();

    Thread(const Thread &original);

    virtual ~Thread();

    bool isAlive() const;

    void start(IWorker *worker);

    void join();

    void terminate()

}


}
}
}


#endif
