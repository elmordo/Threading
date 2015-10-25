#ifndef MEDIT_THREADING_TEST_TESTTHREADMANAGER_HPP
#define MEDIT_THREADING_TEST_TESTTHREADMANAGER_HPP

#include <GTFO/TestCase.hpp>
#include <GTFO/asserts.hpp>

#include "Test_testWorkers.hpp"
#include "../../src/medit/threading/ThreadManager.hpp"

namespace Medit
{
namespace Threading
{
namespace Test
{


GTFO_TESTCASE(TestThreadManager)


GTFO_TESTLIST

    GTFO_REGISTER_TEST(testInit1);
    GTFO_REGISTER_TEST(testCreateThread1);
    GTFO_REGISTER_TEST(testCreateThread2);
    GTFO_REGISTER_TEST(testCreateThread3);
    GTFO_REGISTER_TEST(testRemoveAll1);
    GTFO_REGISTER_TEST(testRemoveAll2);
    GTFO_REGISTER_TEST(testRemoveAll3);
    GTFO_REGISTER_TEST(testRemoveThread1);
    GTFO_REGISTER_TEST(testRemoveThread2);
    GTFO_REGISTER_TEST(testRemoveThread3);
    GTFO_REGISTER_TEST(testGetThreads1);
    GTFO_REGISTER_TEST(testGetThreads2);

GTFO_ENDTESTLIST

    void setUp()
    {
        Thread::killCounter = 0;
    }

    /**
     * @brief test values of empty instance
     *      number of managed threads has to be zero
     */
    void testInit1()
    {
        ThreadManager manager;

        assertEqual(manager.getThreads().size(), 0);
    }

    /**
     * @brief create thread without worker
     */
    void testCreateThread1()
    {
        ThreadManager m;

        Thread *t = m.createThread();

        assertNull(t->getWorker());
        assertEqual(m.getThreads().size(), 1);
    }

    /**
     * @brief create thread with worker
     */
    void testCreateThread2()
    {
        ThreadManager m;
        CountingWorker *worker = createWorker();
        Thread *t = m.createThread(worker);

        assertEqual(t->getWorker(), worker);
        assertEqual(m.getThreads().size(), 1);
    }

    /**
     * @brief create one thread without worker and one with worker
     */
    void testCreateThread3()
    {
        ThreadManager m;
        CountingWorker *worker = createWorker();

        Thread *t1 = m.createThread(), *t2 = m.createThread(worker);

        assertNull(t1->getWorker());
        assertEqual(t2->getWorker(), worker);
        assertEqual(m.getThreads().size(), 2);
    }

    /**
     * @brief remove all threads on empty instance
     */
    void testRemoveAll1()
    {
        ThreadManager m;
        m.removeAll();

        assertEqual(m.getThreads().size(), 0);
        assertEqual(Thread::killCounter, 0);
    }

    /**
     * @brief remove all threads (no thread is running)
     */
    void testRemoveAll2()
    {
        ThreadManager m;
        m.createThread();
        m.createThread();

        m.removeAll();

        assertEqual(m.getThreads().size(), 0);
        assertEqual(Thread::killCounter, 2);
    }

    /**
     * @brief remove all threads (some threads are running)
     */
    void testRemoveAll3()
    {
        IWorker *worker = createWorker();
        ThreadManager m;
        Thread *t1 = m.createThread(worker);
        m.createThread();

        t1->start();

        m.removeAll();

        assertEqual(m.getThreads().size(), 0);
        assertEqual(Thread::killCounter, 2);
    }

    /**
     * @brief remove not existing thread (nothing should happens)
     */
    void testRemoveThread1()
    {
        Thread t;
        ThreadManager m;

        m.removeThread(&t);
    }

    /**
     * @brief remove existing not running thread
     *      thread should be destroyed
     */
    void testRemoveThread2()
    {
        ThreadManager m;
        Thread *t = m.createThread();

        m.removeThread(t);

        assertEqual(m.getThreads().size(), 0);
        assertEqual(Thread::killCounter, 1);
    }

    /**
     * @brief remove existing running thread
     *      thread should be killed before remove
     */
    void testRemoveThread3()
    {
        ThreadManager m;
        Thread *t = m.createThread(createWorker());
        t->start();

        m.removeThread(t);

        assertEqual(m.getThreads().size(), 0);
        assertEqual(Thread::killCounter, 1);
    }

    /**
     * @brief get threads on empty instance
     */
    void testGetThreads1()
    {
        ThreadManager m;
        ThreadManager::ThreadList lst = m.getThreads();

        assertEqual(lst, ThreadManager::ThreadList());
    }

    /**
     * @brief get threads on instance with some managed threads
     */
    void testGetThreads2()
    {
        ThreadManager m;
        ThreadManager::ThreadPtr t1 = m.createThread(),
            t2 = m.createThread();

        ThreadManager::ThreadList lst = m.getThreads();

        assertEqual(lst.size(), 2);

        ThreadManager::ThreadList::iterator pos = lst.begin();

        assertEqual(*pos, t1);
        ++pos;
        assertEqual(*pos, t2);
    }

    CountingWorker *createWorker()
    {
        CountingWorker *worker;
        allocator<CountingWorker> alloc;
        worker = alloc.allocate(1);
        alloc.construct(worker);

        CountingWorker::destroyCounter = 0;

        return worker;
    }

GTFO_ENDCASE


}
}
}



#endif // TESTTHREADMANAGER_HPP
