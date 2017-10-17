#-------------------------------------------------
#
# Project created by QtCreator 2017-10-17T19:45:11
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CourseWork
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sql/dbc.cpp \
    editors/facilityeditor.cpp

HEADERS  += mainwindow.h \
    sql/dbc.h \
    editors/facilityeditor.h

FORMS    += mainwindow.ui \
    editors/facilityeditor.ui
