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
#include "graphs/bfs_paths.hh"

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
  aho_corasick_t ac(patterns);
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
  std::vector<isa::range_t<int>> ranges = {{1, 2}, {4, 5}, {9, 15}};
  isa::range_t<int> range(8, 11);

  auto res = isa::insert_range(ranges, range);

  std::vector<isa::range_t<int>> expected = {{1, 2}, {4, 5}, {8, 15}};

  EXPECT_EQ(expected.size(), res.size());

  for (auto i = 0; i < res.size(); ++i) {
    EXPECT_EQ(res[i], expected[i]);
  }
}

int main(int argc, char *argv[]) {

  /*using GT = isa::graph_t<int, isa::directed_t::directed>;

  GT g;
  g.add_edge(1, 2);
  g.add_edge(1, 3);
  g.add_edge(2, 4);
  g.add_edge(4, 1);

  auto edges = g.get_edges();
  isa::bfs_paths<GT> bf(g, 1);
  bf.build();
  std::size_t dist = bf.get_dist_to(4);

  isa::graph_t<std::string> gg;
  isa::bfs_paths<isa::graph_t<std::string>> sbf(gg, "1");
*/
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
