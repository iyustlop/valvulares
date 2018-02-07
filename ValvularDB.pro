#-------------------------------------------------
#
# Project created by QtCreator 2017-12-04T22:58:11
#
#-------------------------------------------------

QT       += sql core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += sql widgets

TARGET = ValvularDB
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    db/initdb.cpp \
    bean/etiology.cpp \
    bean/person.cpp \
    bean/protesicdisfunction.cpp \
    addvisit.cpp \
    db/ecodb.cpp \
    db/pacientedb.cpp \
    db/citadb.cpp \
    bean/patientbean.cpp \
    bean/eco/ecobean.cpp \
    bean/cita/cita.cpp \
    bean/cita/parametrosanaliticos.cpp \
    bean/cita/visitbean.cpp \
    bean/mitral/mitralbean.cpp \
    db/mitraldb.cpp \
    dialogmitral.cpp \
    dialogeco.cpp

HEADERS  += mainwindow.h \
    db/initdb.h \
    bean/etiology.h \
    bean/person.h \
    bean/protesicdisfunction.h \
    addvisit.h \
    db/ecodb.h \
    db/pacientedb.h \
    db/citadb.h \
    bean/patientbean.h \
    bean/eco/ecobean.h \
    bean/cita/cita.h \
    bean/cita/parametrosanaliticos.h \
    bean/cita/visitbean.h \
    bean/mitral/mitralbean.h \
    db/mitraldb.h \
    dialogmitral.h \
    dialogeco.h

FORMS    += mainwindow.ui \
    addvisit.ui \
    dialogmitral.ui \
    dialogeco.ui
