# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_BUILD_TYPE Debug)

project(project)

add_subdirectory(src/isa)
add_subdirectory(src/isa-pso)
add_subdirectory(src/isa-tests)