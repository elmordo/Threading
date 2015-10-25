#include "Test_testWorkers.hpp"

namespace Medit {
namespace Threading {
namespace Test {

int CommonIterationWorker::destroyCounter = 0;


CountingWorker::CountingWorker()
{
    counter = 0;
}

CountingWorker::~CountingWorker()
{

}

void CountingWorker::iterate()
{
    ++counter;
}

CommonIterationWorker::CommonIterationWorker()
{

}

CommonIterationWorker::~CommonIterationWorker()
{
    ++destroyCounter;
}

}
} // namespace Threading
} // namespace Meit
