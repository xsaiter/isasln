#include <iostream>

#include <gtest/gtest/gtest.h>

#include "msh/t_01.hh"

using namespace tss;

TEST(msh_t_01_a_test, test) {
  std::vector<int> res;
  msh::t_01_a_primes(2, 5, res);
  EXPECT_EQ(res.size(), 3);
  EXPECT_EQ(res[0], 2);
  EXPECT_EQ(res[1], 3);
  EXPECT_EQ(res[2], 5);

  std::vector<int> res2;
  msh::t_01_a_primes(4, 4, res2);
  EXPECT_EQ(res2.size(), 0);
}

TEST(msh_t_01_b_test, test) {
  std::vector<int> a = {40, 20, 10, 10, 10, 5};

  std::string res;
  msh::t_01_b_expr(a, 55, res);
  EXPECT_EQ(res, "40+20+10-10-10+5");

  std::string res2;
  msh::t_01_b_expr(a, 54, res2);
  EXPECT_EQ(res2, "");
}

TEST(msh_t_01_d_test, test) {
  point_s a = {0, 0};
  point_s b = {100, 0};
  point_s c = {0, 100};
  point_s p = {50, 49};

  bool res = tss::msh::t_01_d_tria_pt(a, b, c, p);
  EXPECT_TRUE(res);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
