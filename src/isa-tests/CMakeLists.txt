cmake_minimum_required (VERSION 3.8)

project(isa-tests)

# GTest
enable_testing()
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB_RECURSE src_list "*.hpp" "*.cpp")

add_executable(isa-tests ${src_list})

target_link_libraries(isa-tests isa ${GTEST_LIBRARIES} Threads::Threads)

add_test(isa-tests isa-tests)

#target_compile_options(isa-tests PRIVATE -Werror -Wall -Wextra)
