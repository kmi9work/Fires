#-------------------------------------------------
#
# Project created by QtCreator 2014-02-06T16:12:04
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = em
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    alglibinternal.cpp \
    alglibmisc.cpp \
    ap.cpp \
    dataanalysis.cpp \
    diffequations.cpp \
    fasttransforms.cpp \
    integration.cpp \
    interpolation.cpp \
    linalg.cpp \
    optimization.cpp \
    solvers.cpp \
    specialfunctions.cpp \
    statistics.cpp

HEADERS += \
    dataanalysis.h \
    alglibinternal.h \
    alglibmisc.h \
    ap.h \
    diffequations.h \
    fasttransforms.h \
    integration.h \
    interpolation.h \
    linalg.h \
    optimization.h \
    solvers.h \
    specialfunctions.h \
    statistics.h \
    stdafx.h

OTHER_FILES += \
    em.pro.user
