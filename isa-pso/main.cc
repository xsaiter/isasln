#include <cmath>
#include <iostream>
#include <stack>

#include <gtest/gtest/gtest.h>

#include "dynp/dynp.hh"

#include "numeric.hh"

#include "msh/t_01.hh"
#include "msh/t_02.hh"
#include "msh/t_03.hh"
#include "msh/t_04.hh"
#include "msh/t_05.hh"
#include "msh/t_06.hh"
#include "msh/t_07.hh"
#include "msh/t_08.hh"
#include "msh/t_09.hh"
#include "msh/t_10.hh"
#include "msh/t_11.hh"
#include "msh/t_12.hh"
#include "msh/t_13.hh"
#include "msh/t_14.hh"
#include "msh/t_15.hh"

#include "iom/iom_01.hh"
#include "iom/iom_02.hh"
#include "iom/iom_03.hh"

#include "misc/misc_01.hh"

#include "prb/prb_01.hh"

using namespace isa::geo;

TEST(msh_t_01_a_test, test) {
  std::vector<int> res;
  pso::msh::t_01::a_primes(2, 5, res);
  EXPECT_EQ(res.size(), 3);
  EXPECT_EQ(res[0], 2);
  EXPECT_EQ(res[1], 3);
  EXPECT_EQ(res[2], 5);

  std::vector<int> res2;
  pso::msh::t_01::a_primes(4, 4, res2);
  EXPECT_EQ(res2.size(), 0);
}

TEST(msh_t_01_b_test, test) {
  std::vector<int> a{40, 20, 10, 10, 10, 5};

  std::string res;
  pso::msh::t_01::b_expr(a, 55, res);
  EXPECT_EQ(res, "40+20+10-10-10+5");

  std::string res2;
  pso::msh::t_01::b_expr(a, 54, res2);
  EXPECT_EQ(res2, "");
}

TEST(msh_t_01_d_test, test) {
  auto a = isa::geo::make_point(0, 0);
  auto b = isa::geo::make_point(100, 0);
  auto c = isa::geo::make_point(0, 100);
  auto p = isa::geo::make_point(50, 49);

  bool res = pso::msh::t_01::d_tria_pt(a, b, c, p);
  EXPECT_TRUE(res);
}

TEST(add_least_to_palindrome_test, test) {
  int res = pso::dynp::add_least_to_palindrome("tttyy");
  EXPECT_EQ(res, 2);
}

TEST(house_robber_test, test) {
  std::vector<int> houses{10, 2, 3, 22};
  int res = pso::dynp::house_robber(houses);
  EXPECT_EQ(res, 32);
}

TEST(levenshtein_distance_test, test_levenshtein_distance) {
  int res = pso::dynp::levenshtein_distance("qwe", "qwert");
  EXPECT_EQ(res, 2);
}

TEST(max_common_sequence_test, test) {
  int res = pso::dynp::max_common_sequence("gcataggtc", "agcaatggt");
  EXPECT_EQ(res, 7);
}

TEST(subarray_with_max_sum_test, test) {
  std::vector<int> a{-9, 3, 14, -10};

  pso::dynp::subarray_with_max_sum_res_s res;
  pso::dynp::subarray_with_max_sum(a, res);

  EXPECT_EQ(res.beg, 1);
  EXPECT_EQ(res.end, 2);
  EXPECT_EQ(res.sum, 17);
}

TEST(turtle_travel_test, test) {
  std::vector<std::vector<int>> a{{8, 20, 40}, {5, 11, 27}};
  pso::dynp::turtle_travel_res_s res;
  pso::dynp::turtle_travel(a, 2, 3, res);

  EXPECT_EQ(res.sum, 83);
  EXPECT_EQ(res.path.size(), 4);
}

TEST(largest_square_test, test) {
  std::vector<std::vector<int>> a{
      {0, 1, 0, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 0, 0}, {1, 0, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1}, {1, 0, 1, 1, 1, 1, 1}, {1, 1, 0, 0, 1, 1, 0},
  };

  pso::dynp::largest_square_res_s res;
  pso::dynp::largest_square(a, 6, 7, res);

  EXPECT_EQ(res.side, 3);
  EXPECT_EQ(res.bottom_right_row, 3);
  EXPECT_EQ(res.bottom_right_col, 4);
}

TEST(msh_t_06_a_test, test) {
  std::vector<isa::range_i_u> ranges{{10, 20}, {30, 40}};

  int res = pso::msh::t_06::t_06_a_cover(ranges);

  EXPECT_EQ(res, 20);
}

TEST(msh_t_06_a_test, test_over) {
  std::vector<isa::range_i_u> ranges{{10, 20}, {15, 22}};

  int res = pso::msh::t_06::t_06_a_cover(ranges);

  EXPECT_EQ(res, 12);
}

TEST(msh_t_02_d_segments, test) {
  isa::geo::segment_s<int> seg1{{1, 1}, {4, 4}};
  isa::geo::segment_s<int> seg2{{3, 2}, {5, 2}};

  auto res = pso::msh::t_02::t_02_d_segments(seg1, seg2);
  EXPECT_EQ(res, false);

  isa::geo::segment_s<int> seg3{{3, 2}, {1, 3}};

  auto res2 = pso::msh::t_02::t_02_d_segments(seg1, seg3);
  EXPECT_EQ(res2, true);

  isa::geo::segment_s<int> seg4{{4, 4}, {5, 2}};

  auto res3 = pso::msh::t_02::t_02_d_segments(seg1, seg4);
  EXPECT_EQ(res3, true);
}

TEST(t_04_a_perfect, test) {
  std::vector<int> res;

  pso::msh::t_04::t_04_a_perfect(1, 40, res);

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

TEST(t_11_a_circarea, test) {
  auto c1 = isa::geo::make_circle(20.0, 30.0, 15.0);
  auto c2 = isa::geo::make_circle(40.0, 30.0, 30.0);

  auto res = pso::msh::t_11::t_11_d_circarea(c1, c2);

  auto cmp = std::abs(608.37 - res) <= 0.1;

  EXPECT_TRUE(cmp);
}

TEST(t_05_a_friendly, test) {
  auto res = pso::msh::t_05::t_05_a_friendly(200, 300);

  pso::msh::t_05::divs_s exp{220, 284};

  EXPECT_EQ(*(res.begin()), exp);
}

TEST(t_04_d_area, test) {
  std::vector<isa::geo::point_s<int>> points{{0, 4}, {0, 0}, {3, 0}, {1, 1}};
  auto res = pso::msh::t_04::t_04_d_area(points);

  EXPECT_EQ(3.5, res);
}

TEST(t_05_f_birthday, test) {
  auto days = pso::msh::t_05::t_05_f_birthday(29, 2, 28, 2, 2001);
  EXPECT_EQ(1096, days);

  days = pso::msh::t_05::t_05_f_birthday(5, 5, 19, 4, 2002);
  EXPECT_EQ(16, days);

  days = pso::msh::t_05::t_05_f_birthday(19, 4, 19, 4, 2002);
  EXPECT_EQ(0, days);

  days = pso::msh::t_05::t_05_f_birthday(29, 2, 28, 2, 1992);
  EXPECT_EQ(1, days);
}

TEST(t_05_e_scale, test) {
  auto res = pso::msh::t_05::t_05_e_scale("29234652", 10, 36);
  EXPECT_EQ("HELLO", res);

  res = pso::msh::t_05::t_05_e_scale("78887", 20, 36);
  EXPECT_EQ("PG6F", res);

  res = pso::msh::t_05::t_05_e_scale("78887", 14, 25);
  EXPECT_EQ("II21", res);
}

TEST(iom_01_a_timer, test) {
  auto res = iom::iom_01_a_timer("10:20:50", "15:50:20");

  EXPECT_EQ("2:11:10+1 days", res);
}

TEST(iom_01_c_treasure, test) {
  std::vector<iom::step_s> steps{{1, 3}, {3, 1}, {1, 1},
                                 {3, 3}, {5, 2}, {7, 1}};
  auto res = iom::iom_01_c_treasure(steps);

  EXPECT_EQ(res.x, 3);
  EXPECT_EQ(res.y, 2);
}

TEST(iom_03_a_max_mult, test_pos_and_neg) {
  auto res = iom::iom_03_a_max_mult({3, 5, 1, 7, 9, 0, 9, -3, 10});
  EXPECT_EQ(res.x1, 10);
  EXPECT_EQ(res.x2, 9);
  EXPECT_EQ(res.x3, 9);
}

TEST(iom_03_a_max_mult, test_all_neg) {
  auto res = iom::iom_03_a_max_mult({-8, -3, -5, -1, -7});
  EXPECT_EQ(res.x1, -1);
  EXPECT_EQ(res.x2, -3);
  EXPECT_EQ(res.x3, -5);
}

TEST(iom_03_d_square, test) {
  constexpr int n = 4;

  auto res = iom::iom_03_d_square(n, 2, 2);

  int arr[n][n] = {{1, 1, 1, 1}, {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}};
  auto exp = isa::lia::matrix_s<int>::create<n, n>(arr);

  EXPECT_EQ(res, exp);
}

TEST(misc_is_uniq_chars, test) {
  auto r1 = pso::misc::is_uniq_chars("abcdecx");
  EXPECT_EQ(r1, false);

  auto r2 = pso::misc::is_uniq_chars("abcdex");
  EXPECT_EQ(r2, true);
}

int main(int argc, char *argv[]) {
  std::string s;
  s.assign("helpasda");
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
