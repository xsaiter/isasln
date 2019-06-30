#include <gtest/gtest.h>
#include <iostream>

#include "tests/isa_tests.hh"
#include "tests/pso_tests.hh"

int main(int argc, char *argv[]) {
  pso::msh::t_01::e_power(5, 50);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
