#-------------------------------------------------
#
# Project created by QtCreator 2015-09-02T08:51:19
#
#-------------------------------------------------

QT       -= core gui

TARGET = Threading
TEMPLATE = lib

DEFINES += THREADING_LIBRARY

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += \
    src/medit/threading/IWorker.cpp \
    src/medit/threading/Signal.cpp \
    src/medit/threading/Thread.cpp \
    src/medit/threading/AbstractWorker.cpp \
    src/medit/threading/IterationWorker.cpp \
    src/medit/threading/ThreadManager.cpp \
    tests/threading/Test_testWorkers.cpp

HEADERS +=\
    src/medit/threading/IWorker.hpp \
    src/medit/threading/Signal.hpp \
    src/medit/threading/Thread.hpp \
    src/medit/threading/AbstractWorker.hpp \
    src/medit/threading/IterationWorker.hpp \
    src/medit/threading/ThreadManager.hpp \
    tests/threading/suite.hpp \
    tests/threading/Test_testWorkers.hpp \
    tests/threading/TestThreadManager.hpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}

unix:!macx: LIBS += -L$$PWD/../build-MeditBase-Desktop-Ladění/ -lMeditBase

INCLUDEPATH += $$PWD/../MeditBase/src
DEPENDPATH += $$PWD/../MeditBase/src


TEST {
    TEMPLATE = app

    win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-GTFO-Desktop-Ladění/release/ -lGTFO
    else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-GTFO-Desktop-Ladění/debug/ -lGTFO
    else:unix: LIBS += -L$$PWD/../build-GTFO-Desktop-Ladění/ -lGTFO

    INCLUDEPATH += $$PWD/../GTFO/src
    DEPENDPATH += $$PWD/../GTFO/src

    SOURCES += tests/main.cpp

    HEADERS += tests/threading/TestThread.hpp

    DEFINES += TEST
}
