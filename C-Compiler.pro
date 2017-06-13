QT += core
QT -= gui

CONFIG += c++11

TARGET = C-Compiler
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    compiler.cpp \
    lexicalanalyzer.cpp \
    syntaxanalyzer.cpp

HEADERS += \
    compiler.h \
    lexicalanalyzer.h \
    syntaxanalyzer.h \
    base.h
