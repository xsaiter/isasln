QT       -= core gui

CONFIG += c++14

TARGET = isa
TEMPLATE = lib
CONFIG += staticlib

HEADERS += \    
    numeric/catalan_numbers.hh \
    numeric/numeric.hh \
    strings/str_utils.hh \
    parsing/postfix_to_infix.hh \
    parsing/infix_to_postfix.hh \
    parsing/brackets.hh \    
    sorting/heap_sort.hh \
    sorting/merge_sort.hh \
    sorting/sort.hh \
    misc/all_queens.hh \
    misc/knight_tour.hh \
    misc/lee_alg.hh \
    strings/str_search.hh \
    parsing/calculator.hh \
    strings/aho_corasick.hh

unix {
    target.path = /usr/lib
    INSTALLS += target
}

SOURCES += \    
    numeric/catalan_numbers.cc \
    misc/all_queens.cc \
    misc/knight_tour.cc \
    misc/lee_alg.cc  \
    strings/str_utils.cc \
    parsing/infix_to_postfix.cc \
    parsing/postfix_to_infix.cc \
    parsing/brackets.cc \
    strings/str_search.cc \
    parsing/calculator.cc \
    strings/aho_corasick.cc
