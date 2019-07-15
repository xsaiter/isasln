#include <gtest/gtest.h>
#include <iostream>

#include "tests/isa_tests.hh"
#include "tests/pso_tests.hh"

#include "pso/core.hh"

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
