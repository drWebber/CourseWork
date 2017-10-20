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
    sql/sql.cpp \
    viewers/abstracttableview.cpp \
    viewers/facilityviewer.cpp \
    viewers/athleteviewer.cpp

HEADERS  += mainwindow.h \
    sql/dbc.h \
    sql/sql.h \
    viewers/abstracttableview.h \
    viewers/facilityviewer.h \
    viewers/athleteviewer.h

FORMS    += mainwindow.ui \
    viewers/facilityviewer.ui \
    viewers/athleteviewer.ui

RESOURCES += \
    resource.qrc
