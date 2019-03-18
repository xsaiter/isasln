#include <gtest/gtest.h>
#include <iostream>

#include "tests/isa_tests.hh"
#include "tests/pso_tests.hh"

int main(int argc, char *argv[]) {
  // auto mirror = isa::str::str_mirror("qwe");

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}