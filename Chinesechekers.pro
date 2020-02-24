#-------------------------------------------------
#
# Project created by QtCreator 2019-03-06T21:59:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sans_titre
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG -= debug_and_release debug_and_release_target

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    table.cpp \
    emplacement.cpp \
    boule.cpp \
    joueur.cpp \
    mydialog.cpp \
    myconfig.cpp \
    move.cpp


HEADERS += \
        mainwindow.h \
    table.h \
    emplacement.h \
    boule.h \
    joueur.h \
    main.h \
    mydialog.h \
    myconfig.h \
    move.h

FORMS += \
    mainwindow1.ui \
    mydialog.ui \
    myconfig.ui

RESOURCES += \
    img.qrc


