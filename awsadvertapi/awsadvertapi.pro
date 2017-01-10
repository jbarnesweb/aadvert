QT += core
QT -= gui

CONFIG += c++11

TARGET = awsadvertapi
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    awsrestrequest.cpp

HEADERS += \
    awsrestrequest.h
