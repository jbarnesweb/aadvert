QT += core
QT -= gui

TARGET = awsadvertapi
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    awsrestrequest.cpp \
    itemlookuprequest.cpp

HEADERS += \
    awsrestrequest.h \
    itemlookuprequest.h
