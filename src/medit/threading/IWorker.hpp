#ifndef MEDIT_THREADING_IWORKER_HPP
#define MEDIT_THREADING_IWORKER_HPP

#include <memory>

#include "Signal.hpp"

namespace Medit
{
namespace Threading
{

class IWorker
{
public:

    typedef std::allocator<IWorker> Allocator;

protected:

    /**
     * @brief process incomming singlans
     */
    void processSignals();

public:
    IWorker();

    /**
     * @brief contains worker main logic
     */
    virtual void doAction() = 0;

    /**
     * send signal to thread
     */
    virtual void sendSignal(const Signal &signal) = 0;

};

} // namespace Threading
} // namespace Medit

#endif // MEDIT_THREADING_IWORKER_HPP
