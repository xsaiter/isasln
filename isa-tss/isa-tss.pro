TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    msh/t_01.hh \
    dynp/dynp.hh \
    common.hh \    
    msh/t_02.hh \
    msh/t_06.hh \
    msh/t_04.hh \
    msh/t_10.hh \
    msh/t_11.hh \
    msh/t_05.hh \
    msh/t_03.hh

SOURCES += main.cc \
    msh/t_01.cc \
    dynp/dynp.cc \
    common.cc \
    msh/t_02.cc \
    msh/t_06.cc \
    msh/t_04.cc \
    msh/t_10.cc \
    msh/t_11.cc \
    msh/t_05.cc \
    msh/t_03.cc


LIBS += /usr/lib/libgtest.so

INCLUDEPATH += /usr/include/gtest


unix:!macx: LIBS += -L$$OUT_PWD/../isa/ -lisa

INCLUDEPATH += $$PWD/../isa
DEPENDPATH += $$PWD/../isa

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../isa/libisa.a
