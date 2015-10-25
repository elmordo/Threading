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

    /**
     * @brief set of supported signal types
     */
    enum SIGNAL_TYPES
    {
        SHUT_DOWN,
    };

    typedef std::allocator<IWorker> Allocator;

    /**
     * @brief empty constructor
     */
    IWorker();

    /**
     * @brief destructor
     */
    virtual ~IWorker();

    /**
     * @brief contains worker main logic
     */
    virtual void doAction() = 0;

    /**
     * send signal to thread
     */
    virtual void sendSignal(Signal *signal) = 0;

};

} // namespace Threading
} // namespace Medit

#endif // MEDIT_THREADING_IWORKER_HPP
