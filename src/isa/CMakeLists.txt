cmake_minimum_required (VERSION 3.8)

set(CMAKE_BUILD_TYPE Debug)

project(isa)

file(GLOB_RECURSE src_list "*.hpp" "*.cpp")

add_library (isa ${src_list})

target_include_directories(isa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#target_compile_options(isa PRIVATE -Werror -Wall -Wextra)