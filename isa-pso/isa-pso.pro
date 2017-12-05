TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    msh/t_01.hh \
    dynp/dynp.hh \
    msh/t_02.hh \
    msh/t_06.hh \
    msh/t_04.hh \
    msh/t_10.hh \
    msh/t_11.hh \
    msh/t_05.hh \
    msh/t_03.hh \
    msh/t_07.hh \
    msh/t_08.hh \
    msh/t_09.hh \
    msh/t_12.hh \
    msh/t_13.hh \
    msh/t_14.hh \
    msh/t_15.hh \
    core.hh

SOURCES += main.cc \
    msh/t_01.cc \
    dynp/dynp.cc \
    msh/t_02.cc \
    msh/t_06.cc \
    msh/t_04.cc \
    msh/t_10.cc \
    msh/t_11.cc \
    msh/t_05.cc \
    msh/t_03.cc \
    msh/t_07.cc \
    msh/t_08.cc \
    msh/t_09.cc \
    msh/t_12.cc \
    msh/t_13.cc \
    msh/t_14.cc \
    msh/t_15.cc \
    core.cc


LIBS += /usr/lib/libgtest.so

INCLUDEPATH += /usr/include/gtest


unix:!macx: LIBS += -L$$OUT_PWD/../isa/ -lisa

INCLUDEPATH += $$PWD/../isa
DEPENDPATH += $$PWD/../isa

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../isa/libisa.a
