TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

LIBS += \
       -lboost_system\
       -lboost_filesystem \
      # -lboost_asio

#CXXFLAGS += -DBOOST_NO_CXX11_SCOPED_ENUMS
