#include "gtest/gtest.h"

#include "isa_tests.hpp"
#include "pso_tests.hpp"

int main(int argc, char *argv[]) {
  std::string ss;
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
