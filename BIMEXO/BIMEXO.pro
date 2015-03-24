#-------------------------------------------------
#
# Project created by QtCreator 2015-03-24T11:30:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BIMEXO
TEMPLATE = app


SOURCES += main.cpp\
        qt_exoskeleton.cpp \
    my_maxon_motor.cpp

HEADERS  += qt_exoskeleton.h \
    my_maxon_motor.h \
    Definitions.h

FORMS    += qt_exoskeleton.ui

INCLUDEPATH += $$quote(D:\LIB\Qwt-6.1.2\include)

LIBS +=   $$quote(D:\LIB\Qwt-6.1.2\lib\qwt.lib)
