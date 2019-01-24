#-------------------------------------------------
#
# Project created by QtCreator 2018-11-13T14:11:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = subpacket_parser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    parser/parser.cpp

HEADERS  += mainwindow.h \
    parser/parser.h

FORMS    += mainwindow.ui
