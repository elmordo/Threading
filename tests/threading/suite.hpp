#ifndef MEDIT_THREADING_TEST_SUITE_HPP
#define MEDIT_THREADING_TEST_SUITE_HPP


#include <GTFO/TestSuite.hpp>

#include "TestThread.hpp"
#include "TestThreadManager.hpp"

namespace Medit
{
namespace Threading
{
namespace Test
{

GTFO_TESTSUITE(ThreadingSuite)

    GTFO_REGISTER_TESTCASE(TestThread);
    GTFO_REGISTER_TESTCASE(TestThreadManager);

GTFO_ENDTESTSUITE

}
}
}


#endif // SUITE_HPP
