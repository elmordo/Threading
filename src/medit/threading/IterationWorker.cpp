#include "IterationWorker.hpp"

namespace Medit
{
namespace Threading
{

IterationWorker::IterationWorker()
{
}

IterationWorker::IterationWorker(const IterationWorker &original)
    : AbstractWorker(original)
{
}

IterationWorker::~IterationWorker()
{
}

void IterationWorker::doAction()
{
    // do iterations while shut down flag is true
    while (!getShutDown())
    {
        // do one iteration of computation cycle
        iterate();

        // serve signals
        processSignals();
    }
}

} // namespace Threading
} // namespace Medit
