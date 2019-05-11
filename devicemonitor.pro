#-------------------------------------------------
#
# Project created by QtCreator 2019-04-14T02:36:37
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = devicemonitor
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    setting_page.cpp \
    mainwindow_list_ver.cpp \
    ult_monitor_page.cpp \
    scarray.cpp \
    setting_value.cpp \
    temp_monitor_page.cpp \
    humi_monitor_page.cpp \
    tev_monitor_page.cpp \
    vib_monitor_page.cpp \
    sf6_monitor_page.cpp \
    show_log_page.cpp

HEADERS += \
        mainwindow.h \
    setting_page.h \
    mainwindow_list_ver.h \
    ult_monitor_page.h \
    cancel_bugs.h \
    scarray.h \
    setting_value.h \
    temp_monitor_page.h \
    humi_monitor_page.h \
    tev_monitor_page.h \
    vib_monitor_page.h \
    sf6_monitor_page.h \
    show_log_page.h

FORMS += \
        mainwindow.ui \
    setting_page.ui \
    mainwindow_list_ver.ui \
    ult_monitor_page.ui \
    temp_monitor_page.ui \
    humi_monitor_page.ui \
    tev_monitor_page.ui \
    vib_monitor_page.ui \
    sf6_monitor_page.ui \
    show_log_page.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
