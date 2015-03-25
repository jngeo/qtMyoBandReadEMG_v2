#-------------------------------------------------
#
# Project created by QtCreator 2014-12-20T11:31:19
#
#-------------------------------------------------


QT       += core gui
CONFIG   += qwt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtMyoBandReadEMG
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32 {message("Using win32 configuration")

MYO_PATH = "C:/Myo/myo-sdk-win-0.8.0"
INCLUDEPATH += "$$MYO_PATH/include"
LIBS_PATH += "$$MYO_PATH/Lib" #project compiled using Visual C++ 2010 32bit compiler
    CONFIG(debug, debug|release) {
    LIBS     += -L$$LIBS_PATH \
                -lmyo32
    }
    CONFIG(release, debug|release) {
    LIBS     += -L$$LIBS_PATH \
                -lmyo32
    }
}

