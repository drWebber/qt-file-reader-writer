QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_filereadertest.cpp \
    filereader/filereader.cpp

HEADERS += \
    filereader/filereader.h
