TEMPLATE = app
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += c++1z

SOURCES += \
    main.cc

LIBS += /usr/lib/libgtest.so

INCLUDEPATH += /usr/include/gtest



unix:!macx: LIBS += -L$$OUT_PWD/../isa/ -lisa

INCLUDEPATH += $$PWD/../isa
DEPENDPATH += $$PWD/../isa

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../isa/libisa.a
