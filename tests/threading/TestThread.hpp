#ifndef NEDIT_THREADING_TEST_TESTTHREAD_HPP
#define NEDIT_THREADING_TEST_TESTTHREAD_HPP


#include <GTFO/TestCase.hpp>
#include <GTFO/asserts.hpp>

#include "../../src/medit/threading/Thread.hpp"
#include "Test_testWorkers.hpp"

namespace Medit
{
namespace Threading
{
namespace Test
{

using namespace Sopka::GTFO;
using namespace Medit::Threading;

GTFO_TESTCASE(TestThread)

    GTFO_TESTLIST

        GTFO_REGISTER_TEST(testInit1);
        GTFO_REGISTER_TEST(testInit2);
        GTFO_REGISTER_TEST(testInit3);
        GTFO_REGISTER_TEST(testGetId1);
        GTFO_REGISTER_TEST(testGetId2);
        GTFO_REGISTER_TEST(testIsJoined1);
        GTFO_REGISTER_TEST(testIsJoined2);
        GTFO_REGISTER_TEST(testJoin1);
        GTFO_REGISTER_TEST(testJoin2);
        GTFO_REGISTER_TEST(testStart1);
        GTFO_REGISTER_TEST(testStart2);
        GTFO_REGISTER_TEST(testStart3);
        GTFO_REGISTER_TEST(testWorker1);
        GTFO_REGISTER_TEST(testWorker2);
        GTFO_REGISTER_TEST(testWorker3);
        GTFO_REGISTER_TEST(testAssign);

    GTFO_ENDTESTLIST

    CountingWorker *worker;

    bool autoDestroy;

    virtual void setUp()
    {
        worker = createCountWorker();
        autoDestroy = true;
    }

    virtual void tearDown()
    {
        if (autoDestroy)
        {
            destryCountWorker(worker);
        }
    }


    /**
     * @brief test empty initialization
     */
    void testInit1()
    {
        Thread t;

        assertTrue(t.isJoined());
    }

    /**
     * @brief test initialization with worker and destructor
     */
    void testInit2()
    {
        CountingWorker::destroyCounter = 0;

        Thread::Allocator alloc;
        Thread *t = alloc.allocate(1);

        alloc.construct(t, worker);
        alloc.destroy(t);
        alloc.deallocate(t, 1);

        assertEqual(CountingWorker::destroyCounter, 1);

        autoDestroy = false;
    }

    /**
     * @brief test copytor
     */
    void testInit3()
    {
        Thread t;

        try
        {
            Thread x(t);
        }
        catch (ThreadException &)
        {
            return;
        }

        fail("Copytor has to throw exception");
    }

    void testGetId1()
    {
        Thread t;

        assertEqual(t.getId(), Thread::ThreadId());
    }

    void testGetId2()
    {
        Thread t(worker);
        t.start();
        autoDestroy = false;

        assertNotEqual(t.getId(), Thread::ThreadId());

        t.join();
    }

    /**
     * @brief try to join not running thread
     */
    void testIsJoined1()
    {
        Thread t;

        assertTrue(t.isJoined());
    }

    /**
     * @brief try to join running thread
     */
    void testIsJoined2()
    {
        CountingWorker *worker = createCountWorker();

        Thread t(worker);
        autoDestroy = false;

        t.start();

        try
        {
            assertFalse(t.isJoined());
        }
        catch (Sopka::GTFO::AssertException &e)
        {
            t.join();
            throw e;
        }

        t.join();
    }

    /**
     * @brief try to join not running thread
     */
    void testJoin1()
    {
        Thread t;

        // nothing should happend
        t.join();
    }

    /**
     * @brief try to join running thread
     */
    void testJoin2()
    {
        // join running thread
        Thread t(worker);

        t.start();
        t.join();

        autoDestroy = false;
    }

    /**
     * @brief try to start thread without worker
     *      start thread without worker is not allowed
     */
    void testStart1()
    {
        Thread t;

        try
        {
            t.start();
        }
        catch (ThreadException &e)
        {
            return;
        }

        fail("Thread can not be started without worker");
    }

    /**
     * @brief try to start thread with worker
     *      start thread with worker has to be ok
     */
    void testStart2()
    {
        Thread t(worker);
        t.start();
        autoDestroy = false;

        // pause loop
        for (size_t i = 0; i < 1000*1000; ++i);

        assertNotEqual(worker->counter, 0);
    }

    /**
     * @brief try to start running thread
     *      double start of thread is not allowed
     */
    void testStart3()
    {
        Thread t(worker);

        t.start();
        autoDestroy = false;

        try
        {
            t.start();
        }
        catch (ThreadException &e)
        {
            return;
        }
    }

    /**
     * @brief try to get worker from empty instance
     *      empty instance has worker set to NULL
     */
    void testWorker1()
    {
        Thread t;

        assertNull(t.getWorker());
    }

    /**
     * @brief try to set worker into not running thread
     *      worker can be changed only on not running instance
     */
    void testWorker2()
    {
        Thread t;
        t.setWorker(worker);

        autoDestroy = false;
    }

    /**
     * @brief try to set worker into running thread
     */
    void testWorker3()
    {
        Thread t(worker);
        autoDestroy = false;
        IWorker *newWorker = createCountWorker();

        try
        {
            t.start();
            t.setWorker(newWorker);
        }
        catch (ThreadException &)
        {
            return;
        }

        fail("Worker can not be changed when thread is running");
    }

    /**
     * @brief assign operator should throw exception
     */
    void testAssign()
    {
        try
        {
            Thread t1, t2;
            t1 = t2;
        }
        catch (ThreadException &)
        {
            return;
        }

        fail("Exception was not thrown");
    }

    CountingWorker *createCountWorker()
    {
        allocator<CountingWorker> alloc;
        CountingWorker *worker = alloc.allocate(1);
        alloc.construct(worker);

        return worker;
    }

    void destryCountWorker(CountingWorker *worker)
    {
        allocator<CountingWorker> alloc;
        alloc.destroy(worker);
        alloc.deallocate(worker, 1);
    }


GTFO_ENDCASE

}
}
}


#endif // THREAD_HPP
