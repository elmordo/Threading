#include "AbstractWorker.hpp"

namespace Medit
{
namespace Threading
{

AbstractWorker::AbstractWorker()
{
    shutDown = false;
}

AbstractWorker::~AbstractWorker()
{
}

AbstractWorker::AbstractWorker(const AbstractWorker &original)
{
    // acquire locks on both sides
    original.queueLock.lock();
    queueLock.lock();

    // copy critical data
    incommingSignals = original.incommingSignals;

    // release locks
    original.queueLock.unlock();
    queueLock.unlock();

    // copy common data
    shutDown = original.shutDown;
}

bool AbstractWorker::getShutDown() const
{
    return shutDown;
}

void AbstractWorker::setShutDown(bool val)
{
    shutDown = val;
}

void AbstractWorker::processSignals(size_t num)
{
    // iterate until all signals are processed and/or max processed signals
    // count is reached
    queueLock.lock();

    while (num && incommingSignals.size())
    {
        // get signal and remove it from queue
        Signal *signal = incommingSignals.front();
        incommingSignals.pop();

        // resolve signal type
        if (signal->getSignalType() == SHUT_DOWN)
        {
            // signal is request to shut down. Swt switch and set signal as processed
            shutDown = true;
            signal->markProcessed();
        }

        --num;
    }

    // unlock queue access lock
    queueLock.unlock();
}

void AbstractWorker::sendSignal(Signal *signal)
{
    queueLock.lock();
    incommingSignals.push(signal);
    queueLock.unlock();
}

} // namespace Threading
} // namespace Medit
