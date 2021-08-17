#-------------------------------------------------
#
# Project created by QtCreator 2017-08-31T16:18:57
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QScrollArea
TEMPLATE = app


SOURCES += main.cpp\
        database.cpp \
        mainapp.cpp

HEADERS  += mainapp.h \
    database.h

FORMS    += mainapp.ui
