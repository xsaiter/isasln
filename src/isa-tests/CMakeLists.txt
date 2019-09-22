cmake_minimum_required (VERSION 3.8)

project(isa-tests)

# GTest
enable_testing()
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(isa-tests main.cpp)

target_link_libraries(isa-tests isa ${GTEST_LIBRARIES} Threads::Threads)

add_test(isa-tests isa-tests)