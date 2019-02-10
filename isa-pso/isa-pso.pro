TEMPLATE = app
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++1z

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
    iom/iom_01.hh \
    core.hh \
    iom/iom_02.hh \
    iom/iom_03.hh \
    misc/misc_01.hh \
    shen/shen_01.hh \
    shen/shen_02.hh \
    prb/prb_01.hh

SOURCES += main.cc


LIBS += /usr/lib/libgtest.so

INCLUDEPATH += /usr/include/gtest


unix:!macx: LIBS += -L$$OUT_PWD/../isa/ -lisa

INCLUDEPATH += $$PWD/../isa
DEPENDPATH += $$PWD/../isa

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../isa/libisa.a
