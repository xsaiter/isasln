#include <iostream>
#include <string>
#include <time.h>
#include <vector>

#include <gtest/gtest.h>

#include "isa/bloom_filter.hh"
#include "isa/common.hh"
#include "isa/disjoint_sets.hh"
#include "isa/ranges.hh"
#include "isa/safe_queue.hh"
#include "isa/sort.hh"
#include "isa/vect.hh"

#include "isa/str/aho_corasick.hh"
#include "isa/str/str_search.hh"
#include "isa/str/str_utils.hh"

#include "isa/parsing/brackets.hh"
#include "isa/parsing/calculator.hh"
#include "isa/parsing/finite_automata.hh"

#include "isa/geo/geo.hh"

#include "isa/graphs/dijkstra.hh"
#include "isa/graphs/graph.hh"
#include "isa/graphs/mst.hh"
#include "isa/graphs/paths.hh"

#include "isa/lia/matrix.hh"
#include "isa/lia/vec.hh"

#include "isa/crypto/vigenere_cipher.hh"

using namespace std;

template <class T, class Cmp = less<int>>
void check_sort(void (*sort)(T, T, Cmp)) {
  srand(time(NULL));

  for (int k = 0; k < 10; ++k) {
    int len = rand() % 100;
    if (len == 0) {
      continue;
    }

    vector<int> v;
    v.reserve(len);

    for (int i = 0; i < len; ++i) {
      int item = rand() % 100;
      v.push_back(item);
    }

    less<int> lss;
    sort(v.begin(), v.end(), lss);

    EXPECT_TRUE(is_sorted(v.begin(), v.end()));
  }
}

TEST(test_sort, bubble_sort) {
  check_sort<vector<int>::iterator, less<int>>(&isa::sorting::bubble_sort);
}

TEST(test_sort, insertion_sort) {
  check_sort<vector<int>::iterator, less<int>>(&isa::sorting::insertion_sort);
}

TEST(test_sort, shell_sort) {
  check_sort<vector<int>::iterator, less<int>>(&isa::sorting::shell_sort);
}

TEST(test_sort, selection_sort) {
  check_sort<vector<int>::iterator, less<int>>(&isa::sorting::selection_sort);
}

TEST(test_bloom_filter, bloom_filter) {
  auto filter = isa::make_bloom_filter_str(10);

  filter->add("cat");
  filter->add("dog");

  EXPECT_TRUE(filter->contains("cat"));
  EXPECT_FALSE(filter->contains("yo"));
}

TEST(test_aho_corasick, aho_corasick) {
  std::string s = "sheshe";
  std::vector<std::string> patterns = {"he", "she", "hello"};
  isa::str::Aho_corasick ac(patterns);
  auto result = ac.search(s);

  EXPECT_EQ(result.size(), 4);
}

TEST(test_str, remove_words_with_consecutive_repeated_letters) {
  std::string res =
      isa::str::remove_words_with_consecutive_repeated_letters("word wword");

  EXPECT_EQ(res, "word");
}

TEST(test_ranges, insert_range) {
  std::vector<isa::Range<int>> ranges = {{1, 2}, {4, 5}, {9, 15}};
  isa::Range<int> range(8, 11);

  auto res = isa::insert_range(ranges, range);

  std::vector<isa::Range<int>> expected = {{1, 2}, {4, 5}, {8, 15}};

  EXPECT_EQ(expected.size(), res.size());

  for (std::size_t i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i], expected[i]);
  }
}

TEST(test_graph, dijkstra) {
  using g_u = isa::graphs::graph_i_s<isa::graphs::directions_s::undirected>;

  g_u g(15);
  g.add_edge(1, 2, 7);
  g.add_edge(1, 3, 9);
  g.add_edge(2, 3, 10);

  g.add_edge(1, 6, 14);
  g.add_edge(3, 6, 2);

  g.add_edge(2, 4, 15);
  g.add_edge(3, 4, 11);

  g.add_edge(5, 6, 9);
  g.add_edge(4, 5, 6);

  auto sp = isa::graphs::dijkstra(g, 6);

  auto res = sp.get_path_to(2);

  g_u::edge_u e1(3, 2);
  g_u::edge_u e2(6, 3);

  std::stack<g_u::edge_u> expected;
  expected.push(e1);
  expected.push(e2);

  EXPECT_EQ(expected.size(), res.size());

  while (!res.empty()) {
    auto expected_top = expected.top();
    expected.pop();

    auto actual_top = res.top();
    res.pop();

    EXPECT_EQ(actual_top, expected_top);
  }
}

TEST(test_graph, bfs_paths) {
  using g_u = isa::graphs::graph_i_s<isa::graphs::directions_s::undirected>;

  g_u g(16);
  g.add_edge(1, 2, 7);
  g.add_edge(1, 3, 9);
  g.add_edge(2, 3, 10);

  g.add_edge(1, 6, 14);
  g.add_edge(3, 6, 2);

  g.add_edge(2, 4, 15);
  g.add_edge(3, 4, 11);

  g.add_edge(5, 6, 9);
  g.add_edge(4, 5, 6);

  auto paths = isa::graphs::graph_paths_bfs(g, 1);
  auto dist = paths.distance_to(4);

  EXPECT_EQ(dist, 2);
}

TEST(test_graph, dfs_paths) {
  using g_u = isa::graphs::graph_i_s<isa::graphs::directions_s::undirected>;

  g_u g(16);
  g.add_edge(1, 2, 7);
  g.add_edge(1, 3, 9);
  g.add_edge(2, 3, 10);

  g.add_edge(1, 6, 14);
  g.add_edge(3, 6, 2);

  g.add_edge(2, 4, 15);
  g.add_edge(3, 4, 11);

  g.add_edge(5, 6, 9);
  g.add_edge(4, 5, 6);

  auto paths = isa::graphs::graph_paths_dfs(g, 1);
  auto dist = paths.distance_to(4);

  EXPECT_EQ(dist, 3);
}

TEST(test_str, find_longest_repeated_substr) {
  std::string s = "to be or not to be";

  isa::str::longest_repeated_substr_s res;
  isa::str::find_longest_repeated_substr(s, res);

  EXPECT_EQ(res.all_pos.size(), 2);
  EXPECT_EQ(res.s, "to be");
}

TEST(test_graph, mst_kruskal) {
  using g_u = isa::graphs::graph_i_s<isa::graphs::directions_s::undirected>;

  g_u g(16);
  g.add_edge(1, 2, 7);
  g.add_edge(1, 3, 9);
  g.add_edge(2, 3, 10);

  g.add_edge(1, 6, 14);
  g.add_edge(3, 6, 2);

  g.add_edge(2, 4, 15);
  g.add_edge(3, 4, 11);

  g.add_edge(5, 6, 9);
  g.add_edge(4, 5, 6);

  auto res = isa::graphs::mst_kruskal(g);

  EXPECT_EQ(res.size(), 5);
}

TEST(test_min_of, test) {
  auto res = isa::min_of(10, 2, 3);
  EXPECT_EQ(res, 2);
}

TEST(test_max_of, test) {
  auto res = isa::max_of(10, 2, 3);
  EXPECT_EQ(res, 10);
}

TEST(test_all_eq, test) {
  auto res = isa::all_eq(10, 10, 10);
  EXPECT_TRUE(res);
}

TEST(test_calc_prefix, test) {
  int res = isa::parsing::calculate_prefix("(+ 1 2 (- 3 4 5))");
  EXPECT_EQ(res, -3);
}

TEST(test_vigenere_cipher, test) {
  std::string text = "ATTACKATDAWNZZ";
  std::string key = "LEMON";

  std::string encrypted = isa::crypto::vigenere_encrypt(text, key);
  EXPECT_EQ(encrypted, "LXFOPVEFRNHRLN");

  std::string decrypted = isa::crypto::vigenere_decrypt(encrypted, key);
  EXPECT_EQ(decrypted, text);
}

TEST(test_matrix_add, test) {
  isa::lia::Matrix<> a(3, 3, 2);
  isa::lia::Matrix<> res = a + 10;

  isa::lia::Matrix<> expected(3, 3, 12);

  EXPECT_TRUE(res == expected);
}

TEST(test_matrix_add_self, test) {
  isa::lia::Matrix<int> m(2, 3, 5);
  m += 10;

  isa::lia::Matrix<> expected(2, 3, 15);

  EXPECT_TRUE(m == expected);
}

TEST(test_matrix_create, test) {
  constexpr int n = 2;
  constexpr int m = 2;
  int a[n][m] = {{1, 1}, {1, 1}};
  auto res = isa::lia::Matrix<int>::create<n, m>(a);

  isa::lia::Matrix<> expected(n, m, 1);

  EXPECT_TRUE(res == expected);
}

TEST(test_vec_add, test) {
  isa::lia::Vec<int> a(2, 2);

  isa::lia::Vec<int> b(2, 3);

  isa::lia::Vec<int> r = a + b + a;

  EXPECT_EQ(r.size(), 2);

  for (std::size_t i = 0; i < r.size(); ++i) {
    EXPECT_EQ(r[i], 7);
  }
}

TEST(test_vec_mul, test) {
  isa::lia::Vec<int> a(2, 2);

  isa::lia::Vec<int> b(2, 3);

  isa::lia::Vec<int> r = a * b;

  EXPECT_EQ(r.size(), 2);

  for (std::size_t i = 0; i < r.size(); ++i) {
    EXPECT_EQ(r[i], 6);
  }
}

TEST(test_acc_add, test) {
  int a[] = {1, 2, 3, 4, 5};
  auto res = isa::acc(&(a[0]), &a[5], 0);

  EXPECT_EQ(res, 15);
}

TEST(test_vec_mul_scalar, test) {
  /*isa::lia::vec_s<int> a(2, 2);
  isa::lia::vec_s<int> r(2, 0);
  r = 10 * a;

  EXPECT_EQ(r.size(), 2);

  for (std::size_t i = 0; i < r.size(); ++i) {
    EXPECT_EQ(r[i], 20);
  }*/
}

TEST(test_area_intersection_of_rects, test) {
  auto area = isa::geo::area_intersection_of_rects<int>(
      {{{0, 0}, {5, 3}}, {{3, 1}, {8, 4}}});
  EXPECT_EQ(area, 4);
}
