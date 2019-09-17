TEMPLATE = app
CONFIG += console c++1z
#CONFIG += c++14
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    isa/ar/ar.hh \
    isa/fenwick_tree.hh \
    isa/rb_tree.hh \
    isa/segment_tree.hh \
    isa/str/str_utils.hh \
    isa/geo/geo.hh \
    isa/parsing/postfix_to_infix.hh \
    isa/parsing/infix_to_postfix.hh \
    isa/parsing/brackets.hh \
    isa/misc/all_queens.hh \
    isa/misc/knight_tour.hh \
    isa/graphs/lee_alg.hh \
    isa/str/str_search.hh \
    isa/parsing/calculator.hh \
    isa/str/aho_corasick.hh \
    isa/bloom_filter.hh \
    isa/sort.hh \
    isa/graphs/graph.hh \
    isa/ranges.hh \
    isa/common.hh \
    isa/graphs/dijkstra.hh \
    isa/graphs/paths.hh \
    isa/geo/convex_hull.hh \
    isa/disjoint_sets.hh \
    isa/graphs/mst.hh \
    isa/big_int.hh \
    isa/parsing/finite_automata.hh \
    isa/crypto/vigenere_cipher.hh \
    isa/lia/matrix.hh \
    isa/lia/vec.hh \
    isa/utils.hh \
    isa/safe_queue.hh \
    isa/safe_stack.hh \
    isa/vect.hh \
    pso/msh/t_01.hh \
    pso/dynp/dynp.hh \
    pso/msh/t_02.hh \
    pso/msh/t_06.hh \
    pso/msh/t_04.hh \
    pso/msh/t_10.hh \
    pso/msh/t_11.hh \
    pso/msh/t_05.hh \
    pso/msh/t_03.hh \
    pso/msh/t_07.hh \
    pso/msh/t_08.hh \
    pso/msh/t_09.hh \
    pso/msh/t_12.hh \
    pso/msh/t_13.hh \
    pso/msh/t_14.hh \
    pso/msh/t_15.hh \
    pso/iom/iom_01.hh \
    pso/core.hh \
    pso/iom/iom_02.hh \
    pso/iom/iom_03.hh \
    pso/misc/misc_01.hh \
    pso/preu/p_01_10.hh \
    pso/shen/shen_01.hh \
    pso/shen/shen_02.hh \
    pso/prb/prb_01.hh \
    isa/ar/catalan.hh \
    tests/isa_tests.hh \
    tests/pso_tests.hh

unix {
    target.path = /usr/lib
    INSTALLS += target
}

SOURCES += \
    isa/ar/catalan.cc \
    isa/ar/ar.cc \
    isa/misc/all_queens.cc \
    isa/misc/knight_tour.cc \
    isa/graphs/lee_alg.cc  \    
    isa/parsing/infix_to_postfix.cc \
    isa/parsing/postfix_to_infix.cc \
    isa/parsing/brackets.cc \
    isa/parsing/calculator.cc \
    isa/str/str_utils.cc \
    isa/str/str_search.cc \    
    isa/str/aho_corasick.cc \    
    isa/crypto/vigenere_cipher.cc \
    isa/utils.cc \
    main.cc

LIBS += /usr/lib/libgtest.so

INCLUDEPATH += /usr/include/gtest
