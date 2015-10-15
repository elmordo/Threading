#ifndef MEDIT_THREADING_ABSTRACTWORKER_HPP
#define MEDIT_THREADING_ABSTRACTWORKER_HPP

#include <queue>
#include <mutex>

#include "IWorker.hpp"
#include "Signal.hpp"

using namespace std;


namespace Medit
{
namespace Threading
{

/**
 * @brief provides common functionality of worker
 * in derived class implementation of doAction incomming signals
 * has to be served
 */
class AbstractWorker : public IWorker
{

    /**
     * @brief shut down flag
     */
    bool shutDown;

protected:

    /**
     * @brief container for incomming signals
     */
    typedef queue<Signal*> SignalQueue;

    /**
     * @brief set of incomming signals
     */
    SignalQueue incommingSignals;

    /**
     * @brief lock access to queue
     */
    mutable mutex queueLock;

public:

    /**
     * @brief set of supported signal types
     */
    enum SIGNAL_TYPES
    {
        SHUT_DOWN,
    };

    /**
     * @brief create common instance
     */
    AbstractWorker();

    /**
     * @brief copytor
     * @param original instance with original data
     */
    AbstractWorker(const AbstractWorker &original);

    /**
     * @brief ~AbstractWorker
     */
    virtual ~AbstractWorker();

    /**
     * @brief return shutdown status
     * @return true if shutdown flag is set
     */
    bool getShutDown() const;

    /**
     * @brief set new shutdown flag
     * @param val new value of flag
     */
    void setShutDown(bool val);

    /**
     * @brief process messages in queue
     */
    virtual void processSignals(size_t num=-1);


    // IWorker interface
public:
    virtual void sendSignal(Signal *signal);
};

} // namespace Threading
} // namespace Medit

#endif // MEDIT_THREADING_ABSTRACTWORKER_HPP
