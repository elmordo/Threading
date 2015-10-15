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
    src/medit/threading/IWorker.cpp \
    src/medit/threading/Signal.cpp

HEADERS +=\
    src/medit/threading/IWorker.hpp \
    src/medit/threading/Signal.hpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}

unix:!macx: LIBS += -L$$PWD/../build-MeditBase-Desktop-Ladění/ -lMeditBase

INCLUDEPATH += $$PWD/../MeditBase/src
DEPENDPATH += $$PWD/../MeditBase/src
