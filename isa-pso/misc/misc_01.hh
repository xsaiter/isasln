#pragma once

#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <set>

#include "core.hh"

namespace misc {
namespace details {
int sum_rec_imp(const std::vector<int> &v, std::size_t i) {
  return i < v.size() ? v[i] + sum_rec_imp(v, i + 1) : 0;
}

int first_digit(int x) {
  while ((x % 10) != x) {
    x = (x - x % 10) / 10;
  }
  return x;
}
}
int sum_rec(const std::vector<int> &v) { return details::sum_rec_imp(v, 0); }

std::string compose_max(const std::vector<int> &v) {
  std::vector<int> r(v.size());

  std::partial_sort_copy(v.begin(), v.end(), r.begin(), r.end(),
                         [](int x, int y) {
                           int dx = details::first_digit(x);
                           int dy = details::first_digit(y);
                           return dx > dy;
                         });

  std::ostringstream oss;

  std::copy(r.begin(), r.end(), std::ostream_iterator<int>(oss, ""));

  return oss.str();
}

void remove_dups_from_unsorted_linked_list(
    std::shared_ptr<pso::linked_list_node_s> node) {
  std::set<int> set;
  auto x = node;
  std::shared_ptr<pso::linked_list_node_s> prev = nullptr;
  while (x != nullptr) {
    if (set.find(x->data) != set.end()) { // contains
      prev->next = x->next;
    } else {
      set.insert(x->data);
      prev = x;
    }
    x = x->next;
  }
}

bool str_is_rotaton(const std::string &s1, const std::string &s2) {
  auto n1 = s1.length();
  auto n2 = s2.length();
  if (n1 == n2) {
    auto s3 = s1 + s2;
    return s3.find(s2) != std::string::npos;
  }
  return false;
}
}
