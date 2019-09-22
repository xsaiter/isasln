cmake_minimum_required (VERSION 3.8)

set(CMAKE_BUILD_TYPE Debug)

project(isa)

set(SOURCES 
    utils.cpp 

    ar/ar.cpp
    ar/catalan.cpp

    crypto/vigenere_cipher.cpp
    
    misc/all_queens.cpp
    misc/knight_tour.cpp

    graphs/lee_alg.cpp

    parsing/brackets.cpp
    parsing/calculator.cpp
    parsing/infix_to_postfix.cpp
    parsing/postfix_to_infix.cpp

    str/aho_corasick.cpp
    str/str_search.cpp
    str/str_utils.cpp
   )

set(HEADERS     
    utils.hpp 

    ar/ar.hpp
    ar/catalan.hpp

    crypto/vigenere_cipher.hpp
    
    misc/all_queens.hpp
    misc/knight_tour.hpp

    graphs/lee_alg.hpp

    parsing/brackets.hpp
    parsing/calculator.hpp
    parsing/infix_to_postfix.hpp
    parsing/postfix_to_infix.hpp

    str/aho_corasick.hpp
    str/str_search.hpp
    str/str_utils.hpp
   )

add_library (isa ${SOURCES} ${HEADERS})

target_include_directories(isa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
