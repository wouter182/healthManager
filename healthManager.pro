#-------------------------------------------------
#
# Project created by QtCreator 2014-12-17T17:05:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = healthManager
TEMPLATE = app

SOURCES +=  main.cpp\
            mainwindow.cpp \
            UsbData.cpp \
            UsbDownloader.cpp \
            UserMeasurement.cpp \
            UserData.cpp

HEADERS  += mainwindow.h \
            UsbData.h \
            UsbDownloader.h \
            UserData.h \
            UserMeasurement.h

FORMS    += mainwindow.ui


LIBS     += -L/usr/lib/x86_64-linux-gnu/ -lusb-1.0
