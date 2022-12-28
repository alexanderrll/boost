QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = asio_client_out
TEMPLATE = app
INCLUDEPATH += src/ \
               include/ \
               ../common/src \
               ../common/include
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/mainwindowclient.cpp \
    src/chat_client.cpp \
    ../common/src/chat_message.cpp \
    src/threadworkerclient.cpp

HEADERS += \
    include/mainwindowclient.h \
    include/chat_client.h \
    ../common/src/chat_message.h \
    include/threadworkerclient.h

FORMS += \
    ui/mainwindowclient.ui

LIBS += \
       -lboost_system
