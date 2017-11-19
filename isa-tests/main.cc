#include <iostream>
#include <vector>
#include <time.h>
#include <string>

#include <gtest/gtest/gtest.h>

#include "sort.hh"
#include "heap_sort.hh"
#include "merge_sort.hh"

#include "strings/str_utils.hh"
#include "strings/str_search.hh"
#include "strings/aho_corasick.hh"

#include "bloom_filter.hh"
#include "ranges.hh"

#include "graphs/graph.hh"
#include "graphs/paths.hh"
#include "graphs/dijkstra.hh"
#include "graphs/mst.hh"

#include "disjoint_sets.hh"

#include "parsing/finite_automata.hh"

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
  isa::strings::aho_corasick_s ac(patterns);
  auto result = ac.search(s);

  EXPECT_EQ(result.size(), 4);
}

TEST(test_str, remove_words_with_consecutive_repeated_letters) {
  std::string res =
      isa::strings::remove_words_with_consecutive_repeated_letters(
          "word wword");

  EXPECT_EQ(res, "word");
}

TEST(test_ranges, insert_range) {
  std::vector<isa::range_s<int>> ranges = {{1, 2}, {4, 5}, {9, 15}};
  isa::range_s<int> range(8, 11);

  auto res = isa::insert_range(ranges, range);

  std::vector<isa::range_s<int>> expected = {{1, 2}, {4, 5}, {8, 15}};

  EXPECT_EQ(expected.size(), res.size());

  for (std::size_t i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i], expected[i]);
  }
}

TEST(test_graph, dijkstra) {
  using g_u = isa::graph_i_s<isa::directed_s::undirected>;

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

  auto sp = isa::dijkstra(g, 6);

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
  using g_u = isa::graph_i_s<isa::directed_s::undirected>;

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

  auto paths = isa::graph_paths_bfs(g, 1);
  auto dist = paths.distance_to(4);

  EXPECT_EQ(dist, 2);
}

TEST(test_graph, dfs_paths) {
  using g_u = isa::graph_i_s<isa::directed_s::undirected>;

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

  auto paths = isa::graph_paths_dfs(g, 1);
  auto dist = paths.distance_to(4);

  EXPECT_EQ(dist, 3);
}

TEST(test_str, find_longest_repeated_substr) {
  std::string s = "to be or not to be";

  isa::strings::longest_repeated_substr_s res;
  isa::strings::find_longest_repeated_substr(s, res);

  EXPECT_EQ(res.all_pos.size(), 2);
  EXPECT_EQ(res.s, "to be");
}

TEST(test_graph, mst_kruskal) {
  using g_u = isa::graph_i_s<isa::directed_s::undirected>;

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

TEST(test_dfa, dfa) {
  isa::dfa_s<char> dfa(0);

  dfa.add_state(0, false);
  dfa.add_state(1, false);
  dfa.add_state(2, true);

  dfa.add_transition(0, 1, 'a');
  dfa.add_transition(1, 2, 'b');

  dfa.next('a');
  dfa.next('b');

  auto is_final_state = dfa.is_accept();

  EXPECT_TRUE(is_final_state);
}

TEST(test_nfa_regex, nfa_regex) {
  auto nfa = isa::make_nfa_regex("(ab*a)");
  bool accept = nfa.accept("abbba");
  EXPECT_TRUE(accept);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
