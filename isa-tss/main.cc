#include <iostream>
#include <math.h>

#include <gtest/gtest/gtest.h>

#include "dynp/dynp.hh"

#include "numeric.hh"

#include "msh/t_01.hh"
#include "msh/t_02.hh"
#include "msh/t_04.hh"
#include "msh/t_06.hh"
#include "msh/t_10.hh"

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

TEST(add_least_to_palindrome_test, test) {
  int res = dynp::add_least_to_palindrome("tttyy");
  EXPECT_EQ(res, 2);
}

TEST(house_robber_test, test) {
  std::vector<int> houses = {10, 2, 3, 22};
  int res = dynp::house_robber(houses);
  EXPECT_EQ(res, 32);
}

TEST(levenshtein_distance_test, test_levenshtein_distance) {
  int res = dynp::levenshtein_distance("qwe", "qwert");
  EXPECT_EQ(res, 2);
}

TEST(max_common_sequence_test, test) {
  int res = dynp::max_common_sequence("gcataggtc", "agcaatggt");
  EXPECT_EQ(res, 7);
}

TEST(subarray_with_max_sum_test, test) {
  std::vector<int> a = {-9, 3, 14, -10};

  dynp::subarray_with_max_sum_res_s res;
  dynp::subarray_with_max_sum(a, res);

  EXPECT_EQ(res.beg, 1);
  EXPECT_EQ(res.end, 2);
  EXPECT_EQ(res.sum, 17);
}

TEST(turtle_travel_test, test) {
  std::vector<std::vector<int>> a = {{8, 20, 40}, {5, 11, 27}};
  dynp::turtle_travel_res_s res;
  dynp::turtle_travel(a, 2, 3, res);

  EXPECT_EQ(res.sum, 83);
  EXPECT_EQ(res.path.size(), 4);
}

TEST(largest_square_test, test) {
  std::vector<std::vector<int>> a = {
      {0, 1, 0, 1, 1, 1, 1},
      {0, 1, 1, 1, 1, 0, 0},
      {1, 0, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1},
      {1, 0, 1, 1, 1, 1, 1},
      {1, 1, 0, 0, 1, 1, 0},
  };

  dynp::largest_square_res_s res;
  dynp::largest_square(a, 6, 7, res);

  EXPECT_EQ(res.side, 3);
  EXPECT_EQ(res.bottomRightRow, 3);
  EXPECT_EQ(res.bottomRightCol, 4);
}

TEST(msh_t_06_a_test, test) {
  std::vector<isa::range_i_s> ranges = {{10, 20}, {30, 40}};

  int res = tss::msh::t_06_a_cover(ranges);

  EXPECT_EQ(res, 20);
}

TEST(msh_t_06_a_test, test_over) {
  std::vector<isa::range_i_s> ranges = {{10, 20}, {15, 22}};

  int res = tss::msh::t_06_a_cover(ranges);

  EXPECT_EQ(res, 12);
}

TEST(msh_t_02_d_segments, test) {
  tss::segment_s seg1{tss::point_s{1, 1}, tss::point_s{4, 4}};
  tss::segment_s seg2{tss::point_s{3, 2}, tss::point_s{5, 2}};

  auto res = tss::msh::t_02_d_segments(seg1, seg2);
  EXPECT_EQ(res, false);

  tss::segment_s seg3{tss::point_s{3, 2}, tss::point_s{1, 3}};

  auto res2 = tss::msh::t_02_d_segments(seg1, seg3);
  EXPECT_EQ(res2, true);

  tss::segment_s seg4{tss::point_s{4, 4}, tss::point_s{5, 2}};

  auto res3 = tss::msh::t_02_d_segments(seg1, seg4);
  EXPECT_EQ(res3, true);
}

TEST(t_04_a_perfect, test) {
  std::vector<int> res;

  tss::msh::t_04_a_perfect(1, 40, res);

  EXPECT_EQ(res.size(), 2);
}

TEST(is_perfec_test, test) {
  bool yes = isa::is_perfect_num(28);

  EXPECT_TRUE(yes);
}

/*TEST(t_10_b_fibostr, test) {
  int res = tss::msh::t_10_b_fibostr(8, "bbabab");

  EXPECT_EQ(res, 3);
}*/

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
