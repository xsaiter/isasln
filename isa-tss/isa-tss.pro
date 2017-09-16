TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    msh/t_01.hh \
    common.hh \
    common.hh

SOURCES += main.cc \
    msh/t_01.cc \
    common.cc


LIBS += /usr/lib/libgtest.so

INCLUDEPATH += /usr/include/gtest


unix:!macx: LIBS += -L$$OUT_PWD/../isa/ -lisa

INCLUDEPATH += $$PWD/../isa
DEPENDPATH += $$PWD/../isa

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../isa/libisa.a
