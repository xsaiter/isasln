#include <gtest/gtest.h>
#include <iostream>

#include "tests/isa_tests.hh"
#include "tests/pso_tests.hh"

int main(int argc, char *argv[]) {
  // auto mirror = isa::str::str_mirror("qwe");
  std::cout << "HELLOE" << std::endl;
  std::string s;
  auto x = s.begin();

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
