QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = asio_server_out
TEMPLATE = app
INCLUDEPATH += src/ \
               include/ \
               ../common/src/ \
               ../common/include \
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/mainwindowserver.cpp \
    src/chat_room.cpp \
    src/chat_server.cpp \
    src/chat_session.cpp \
    ../common/src/chat_message.cpp \
    src/threadworkerserver.cpp

HEADERS += \
    include/mainwindowserver.h \
    include/chat_participant.h \
    include/chat_room.h \
    include/chat_server.h \
    include/chat_session.h \
    ../common/include/chat_message.h \
    include/threadworkerserver.h

FORMS += \
    ui/mainwindowserver.ui

LIBS += \
       -lboost_system
