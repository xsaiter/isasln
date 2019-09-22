cmake_minimum_required (VERSION 3.8)

set(CMAKE_BUILD_TYPE Debug)

project(isa-pso)

add_executable(isa-pso main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/src)

target_link_libraries(isa-pso isa)