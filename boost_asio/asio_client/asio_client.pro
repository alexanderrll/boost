QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = asio_client_out
TEMPLATE = app
INCLUDEPATH += ../common/src \
               ../common/ui
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindowclient.cpp \
    chat_client.cpp \
    ../common/src/chat_message.cpp \
    threadworkerclient.cpp

HEADERS += \
    mainwindowclient.h \
    chat_client.h \
    ../common/src/chat_message.h \
    threadworkerclient.h

FORMS += \
    ../common/ui/mainwindow.ui

LIBS += \
       -lboost_system
