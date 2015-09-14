#-------------------------------------------------
#
# Project created by QtCreator 2015-09-02T08:51:19
#
#-------------------------------------------------

QT       -= core gui

TARGET = Threading
TEMPLATE = lib

DEFINES += THREADING_LIBRARY

SOURCES += \
    src/medit/threading/linux/Thread.cpp \
    src/medit/threading/IWorker.cpp \
    src/medit/threading/ISignal.cpp

HEADERS +=\
    src/medit/threading/linux/Thread.hpp \
    src/medit/threading/IWorker.hpp \
    src/medit/threading/ISignal.hpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}