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
    src/medit/threading/Thread.cpp

HEADERS +=\
    src/medit/threading/IWorker.hpp \
    src/medit/threading/Signal.hpp \
    src/medit/threading/Thread.hpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}

unix:!macx: LIBS += -L$$PWD/../build-MeditBase-Desktop-Ladění/ -lMeditBase

INCLUDEPATH += $$PWD/../MeditBase/src
DEPENDPATH += $$PWD/../MeditBase/src
