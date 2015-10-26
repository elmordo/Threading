Medit Threading library
=======================

Library provides basic interface to manage threads in C++ using std::thread of C++11 standard.

Requirements
------------

* `MeditBase` library for some macros and base exception definition (https://github.com/elmordo/MeditBase.git)
* `GTFO` test library only for test build target (https://github.com/elmordo/GTFO.git)

Compiling
---------

To compile library use QMake by `qmake` command to generate makefiles and then `make` and `make install`
Use `qmake CONFIG+=TEST` to compile test application (GTFO required)

Usage
-----

Use `ThreadManager` class to manage your threads automatically (thread instances and its workers are destroyed when manager is destroyed).
Implement your logic into `AbstractWorker::doAction()`. Do not forget process incomming signals!
For program running in loops, use `IterationWorker` class. This class has pure virtual method `IterationWorker::iterate()` called from implementation of `doAction` method. Incomming signals are processed after every iteration.

Planned features
----------------

Pool thread manager to manage limited pool of threads.
