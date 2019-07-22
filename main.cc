#include <gtest/gtest.h>
#include <iostream>

#include "tests/isa_tests.hh"
#include "tests/pso_tests.hh"

#include "pso/core.hh"

int main(int argc, char *argv[]) {
  std::vector<int> v;
  isa::ar::Is_prime_num<int> nums(3, 20);
  for (int x : nums) {
    v.push_back(x);
  }
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
