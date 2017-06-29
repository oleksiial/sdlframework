#-------------------------------------------------
#
# Project created by QtCreator 2017-06-27T20:07:36
#
#-------------------------------------------------

QT       -= core gui

QMAKE_CXXFLAGS += -std=c++14

TARGET = SDLFramework
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    gfxengine.cpp \
    gfxengine/gfxengine.cpp \
    core/components/sprite.cpp \
    core/components/transform.cpp \
    gfxengine/resourceloader.cpp \
    gfxengine/resourcecontainer.cpp \
    utilities/log.cpp

HEADERS += \
    gfxengine.h \
    gfxengine/gfxengine.h \
    core/components/component.h \
    core/components/sprite.h \
    core/components/transform.h \
    core/container.h \
    gfxengine/resourceloader.h \
    gfxengine/resourcecontainer.h \
    gfxengine/resourcepreloadholder.h \
    utilities/log.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
