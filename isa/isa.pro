QT       -= core gui

CONFIG += c++1z

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
    misc/all_queens.hh \
    misc/knight_tour.hh \
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
    crypto/vigenere_cipher.hh \
    lia/matrix.hh \
    lia/vec.hh \
    utils.hh \    
    safe_queue.hh \
    safe_stack.hh \
    vect.hh

unix {
    target.path = /usr/lib
    INSTALLS += target
}

SOURCES += \    
    catalan_numbers.cc \
    misc/all_queens.cc \
    misc/knight_tour.cc \
    graphs/lee_alg.cc  \
    strings/str_utils.cc \
    parsing/infix_to_postfix.cc \
    parsing/postfix_to_infix.cc \
    parsing/brackets.cc \
    strings/str_search.cc \
    parsing/calculator.cc \
    strings/aho_corasick.cc \
    numeric.cc \        
    crypto/vigenere_cipher.cc \
    utils.cc
