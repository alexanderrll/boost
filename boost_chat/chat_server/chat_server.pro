######################################################################
# Automatically generated by qmake (3.1) Sat Dec 10 17:54:26 2022
######################################################################

TEMPLATE = app
TARGET = chat_server.out
INCLUDEPATH +=  . \
                ../common \
# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
SOURCES += main.cpp \
    chat_room.cpp \
    chat_server.cpp \
    chat_session.cpp \
    ../common/chat_message.cpp

HEADERS += \
    chat_participant.h \
    chat_room.h \
    chat_server.h \
    chat_session.h \
    ../common/chat_message.h
