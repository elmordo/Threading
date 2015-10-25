#ifndef MEIT_THREADING_TEST_TESTWORKERS_HPP
#define MEIT_THREADING_TEST_TESTWORKERS_HPP

#include "../../src/medit/threading/AbstractWorker.hpp"
#include "../../src/medit/threading/IterationWorker.hpp"


namespace Medit
{
namespace Threading
{
namespace Test
{

class CommonIterationWorker : public Medit::Threading::IterationWorker
{

public:

    static int destroyCounter;

    CommonIterationWorker();

    virtual ~CommonIterationWorker();

};

class CountingWorker : public CommonIterationWorker
{

public:

    size_t counter;

    CountingWorker();

    virtual ~CountingWorker();

    // IterationWorker interface
public:
    virtual void iterate();
};


}
} // namespace Threading
} // namespace Meit

#endif // MEIT_THREADING_TEST_TESTWORKERS_HPP
