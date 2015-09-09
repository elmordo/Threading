About
=====

Threading library provides multiplatform thread representation by class and basic synchronization primitives.

Threads
-------

Because of different OS api for threads, more trhread implementations have to be done.

Workers
-------

Workers are main classes of all threads. They do assigned work and handle incomming signals. Signals have to be handled manualy from "work" method of class.
All workers have to implement interface defined by class IWorker. This class contains methods:

* doWork - contains main thread logic
* processSignals - protected method able to process incomming signals. 
* sendSignal - send signal into thread (add signal to queue processed by processSignal methods)

Because most of threads implement methods above same, `AbstractThread` class was created. This class implements methods `processSignals` and `sendSignal`. Has internal signal queue with thread lock and when `sendSignal` is called, lock is acquired, signal is added into queue and after that lock is released. Similarly to to `sendSignal`, method `processSignals` acquire lock and process signals. If some signal can not be processed (unknown type of signal), nothing happened. Because application can define its own types of signals, `processSignals` method is virtual and can be overriden.
Class `AbstractThread` also defines flag `shutdown`. When it is become `True`, end of thread is requested. This flag can be accessed by `getShutdownStatus` method.

Thread to thread communication
------------------------------

Threads can communicate with each other by signals. All signals implemnets `ISignal` interface:

* `getType` - get signal type (should be unique in whole program
* `getData` - returns pointer to void pointing to data. If no data is set, return 0x0

All signals should be send by `ThreadManager` class.
`ISignal` class also defines `SignalAllocator` type. This type is used to deallocate all allocated signal pointers.

Synchronization primitives
--------------------------

