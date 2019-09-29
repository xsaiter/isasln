cmake_minimum_required (VERSION 3.8)

set(CMAKE_BUILD_TYPE Debug)

project(isa-pso)

file(GLOB_RECURSE src_list "*.hpp" "*.cpp")

add_executable(isa-pso ${src_list})

include_directories(${CMAKE_SOURCE_DIR}/src)

target_link_libraries(isa-pso isa)
