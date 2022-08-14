#-------------------------------------------------
# Project created by QtCreator 2012-12-24T11:15:52
#-------------------------------------------------

QT       = core gui widgets multimedia

TARGET   = TaskAutomator

TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    taskdialog.cpp \
    configurationdialog.cpp \
    reminddialog.cpp \
    task.cpp \
    tasklist.cpp \
    configurationmanager.cpp \
    actionstarter.cpp \
    aboutdialog.cpp

HEADERS += globals.h \
    mainwindow.h \
    taskdialog.h \
    configurationdialog.h \
    reminddialog.h \
    task.h \
    tasklist.h \
    configurationmanager.h \
    actionstarter.h \
    aboutdialog.h

FORMS   += mainwindow.ui \
    taskdialog.ui \
    configurationdialog.ui \
    reminddialog.ui \
    aboutdialog.ui

TRANSLATIONS = taskautomator_pt.ts

RESOURCES = qtresource.qrc

RC_FILE = winresource.rc

VERSION = 0.0.1

QMAKE_TARGET_PRODUCT = "Task Automator"

QMAKE_TARGET_COPYRIGHT = "Copyright (C) 2010-2022 Daniel T. McGinnis"
