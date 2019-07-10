#include <gtest/gtest.h>
#include <iostream>

#include "tests/isa_tests.hh"
#include "tests/pso_tests.hh"

#include "pso/core.hh"

int main(int argc, char *argv[]) {
  pso::msh::t_03::F_serpent().run(5);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
