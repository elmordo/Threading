#ifndef MEDIT_THREADING_THREAD_HPP
#define MEDIT_THREADING_THREAD_HPP

#include <thread>
#include <queue>
#include <medit/meditbase/base.hpp>

#include "IWorker.hpp"

using namespace std;


namespace Medit
{
namespace Threading
{

MEDIT_CREATE_EXCEPTION_E(MeditBase::BaseException, ThreadException)

    THREAD_IS_RUNNING,
    THREAD_CAN_NOT_BE_COPIED,

MEDIT_END_EXCEPTION_E;

/**
 * @brief thread wrapper class
 */
class Thread
{
public:

    typedef thread::id threadId;

    /**
     * @brief real thread
     */
    thread internalThread;

    /**
     * @brief worker running in thread
     */
    IWorker *worker;

public:

    /**
     * @brief create uninitialized instance
     */
    Thread();

    /**
     * @brief create instance with worker
     * @param worker worker to set
     */
    Thread(IWorker *worker);

    /**
     * @brief copytor (override standard copytor to throw exception)
     * @param original original instance
     * @throw ThreadException every time it is called
     */
    Thread(const Thread &original);

    /**
     * @brief join thread if running and destroy worker if set
     */
    virtual ~Thread();

    /**
     * @brief return current thread id
     * @return
     */
    threadId getId() const;

    /**
     * @brief test if thread was joined
     * @return true if worker finished its job
     */
    bool isJoined() const;

    /**
     * @brief join thread (blocking)
     */
    void join();

    /**
     * @brief start thread
     */
    void start();

    /**
     * @brief return current worker
     * @return pointer to worker
     */
    IWorker *getWorker() const;

    /**
     * @brief set new worker to instance
     * @param value new worker to set
     * @throw ThreadException thread is running (it is not joined)
     */
    void setWorker(IWorker *value);

    /**
     * @brief override standard assign operator to throw exception
     * @param original instance with original data
     * @return reference to self
     * @throw ThreadException thrown everytime
     */
    Thread &operator =(const Thread &original);
};

} // namespace Threading
} // namespace Medit

#endif // MEDIT_THREADING_THREAD_HPP
