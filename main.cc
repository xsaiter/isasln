#include <gtest/gtest.h>
#include <iostream>

#include "tests/isa_tests.hh"
#include "tests/pso_tests.hh"

#include "pso/core.hh"

int main(int argc, char *argv[]) {
  std::vector<std::string> res;
  std::string s = "aa-bb-cc-dd";
  isa::split(s.begin(), s.end(), std::back_inserter(res), '-',
             isa::convert_to_str<>);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
