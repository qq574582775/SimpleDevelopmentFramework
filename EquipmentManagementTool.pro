#-------------------------------------------------
#
# Project created by QtCreator 2018-04-22T19:54:14
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartSoloDeviceManager
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    appinit.cpp \
    navlistview.cpp \
    sliderbar.cpp \
    uidemo5.cpp \
    quiwidget.cpp

HEADERS += \
    appinit.h \
    navlistview.h \
    sliderbar.h \
    uidemo5.h \
    quiwidget.h \
    head.h

FORMS += \
    uidemo5.ui

RESOURCES += \
    demo.qrc \
    image.qrc \
    main.qrc \
    qss.qrc
	

win32:CONFIG(release, debug|release):  DESTDIR = ../../Release
else:win32:CONFIG(debug, debug|release): DESTDIR = ../../Debug 
