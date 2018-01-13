QT       -= core gui

CONFIG += c++14

TARGET = isa
TEMPLATE = lib
CONFIG += staticlib

HEADERS += \    
    catalan_numbers.hh \
    numeric.hh \
    strings/str_utils.hh \
    geo/geo.hh \
    parsing/postfix_to_infix.hh \
    parsing/infix_to_postfix.hh \
    parsing/brackets.hh \        
    all_queens.hh \
    knight_tour.hh \
    graphs/lee_alg.hh \
    strings/str_search.hh \
    parsing/calculator.hh \
    strings/aho_corasick.hh \
    bloom_filter.hh \            
    sort.hh \
    graphs/graph.hh \
    ranges.hh \    
    common.hh \
    graphs/dijkstra.hh \
    graphs/paths.hh \
    geo/convex_hull.hh \    
    disjoint_sets.hh \
    graphs/mst.hh \
    vlong.hh \     
    parsing/finite_automata.hh \
    crypto/vigenere_cipher.hh

unix {
    target.path = /usr/lib
    INSTALLS += target
}

SOURCES += \    
    catalan_numbers.cc \
    all_queens.cc \
    knight_tour.cc \
    graphs/lee_alg.cc  \
    strings/str_utils.cc \
    parsing/infix_to_postfix.cc \
    parsing/postfix_to_infix.cc \
    parsing/brackets.cc \
    strings/str_search.cc \
    parsing/calculator.cc \
    strings/aho_corasick.cc \
    numeric.cc \
    geo/geo.cc \
    geo/convex_hull.cc \
    common.cc \
    vlong.cc \
    crypto/vigenere_cipher.cc
