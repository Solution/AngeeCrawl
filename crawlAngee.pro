QT += core network
QT -= gui

TARGET = crawlAngee
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    angeecrawlapplication.cpp \
    crawlworkerthread.cpp \
    httpdownloader.cpp \
    page.cpp

HEADERS += \
    angeecrawlapplication.h \
    crawlworkerthread.h \
    httpdownloader.h \
    page.h \
    appdefaults.h

