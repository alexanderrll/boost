QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = asio_server_out
TEMPLATE = app
INCLUDEPATH += ../common
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindowserver.cpp \
    chat_room.cpp \
    chat_server.cpp \
    chat_session.cpp \
    ../common/chat_message.cpp \
    threadworkerserver.cpp

HEADERS += \
    mainwindowserver.h \
    chat_participant.h \
    chat_room.h \
    chat_server.h \
    chat_session.h \
    ../common/chat_message.h \
    threadworkerserver.h

FORMS += \
    mainwindowserver.ui

LIBS += \
       -lboost_system
