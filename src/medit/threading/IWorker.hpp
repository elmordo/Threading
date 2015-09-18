#ifndef MEDIT_THREADING_IWORKER_HPP
#define MEDIT_THREADING_IWORKER_HPP

namespace Medit
{
namespace Threading
{

class IWorker
{

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
    void sendSignal(const ISignal &signal) = 0;

};

} // namespace Threading
} // namespace Medit

#endif // MEDIT_THREADING_IWORKER_HPP
