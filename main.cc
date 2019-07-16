#include <gtest/gtest.h>
#include <iostream>

#include "tests/isa_tests.hh"
#include "tests/pso_tests.hh"

#include "pso/core.hh"

int main(int argc, char *argv[]) {
  std::vector<int> primes;
  isa::ar::Prime_nums<int> nums(4, 8);
  for (auto num : nums) {
    primes.push_back(num);
  }
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
