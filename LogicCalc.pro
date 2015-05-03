#-------------------------------------------------
#
# Project created by QtCreator 2015-04-29T11:51:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LogicCalc
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    spinboxdelegate.cpp \
    logicfunction.cpp \
    dialogshowfunc.cpp \
    funcinputvalidator.cpp

HEADERS  += mainwindow.h \
    spinboxdelegate.h \
    logicfunction.h \
    dialogshowfunc.h \
    funcinputvalidator.h

FORMS    += mainwindow.ui \
    dialogshowfunc.ui

RESOURCES += \
    res.qrc
