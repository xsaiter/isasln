#include <iostream>
#include <vector>
#include <time.h>
#include <string>

#include <gtest/gtest/gtest.h>

#include "sorting/sort.hh"
#include "sorting/heap_sort.hh"
#include "sorting/merge_sort.hh"

#include "strings/str_utils.hh"
#include "strings/str_search.hh"
#include "strings/aho_corasick.hh"

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

    bool ok = is_sorted(v.begin(), v.end());

    ASSERT_TRUE(ok);
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

TEST(test_sort, gnome_sort) {
  check_sort<vector<int>::iterator, less<int>>(&isa::sorting::gnome_sort);
}

/*void test_aho_corasick() {
  std::string s = "sheshe";
  std::vector<std::string> patterns = {"he", "she", "hello"};
  aho_corasick_t ac(patterns);
  auto result = ac.search(s);
  auto tmp = result;
}*/

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
