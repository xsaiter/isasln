#pragma once

#include <algorithm>
#include <iterator>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "pso/core.hh"

namespace pso::misc {
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
} // namespace details

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

void remove_dups_from_unsorted_linked_list(pso::Slnp node) {
  std::set<int> set;
  auto x = node;
  pso::Slnp prev = nullptr;
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

bool str_is_rotation(const std::string &s1, const std::string &s2) {
  const auto n1 = s1.length();
  const auto n2 = s2.length();
  if (n1 == n2) {
    const auto s3 = s1 + s2;
    return s3.find(s2) != std::string::npos;
  }
  return false;
}

bool is_uniq_chars(const std::string &s) {
  u_int8_t x = 0;
  for (char c : s) {
    int v = c - 'a';
    if ((x & 1 << v) > 0) {
      return false;
    }
    x |= 1 << v;
  }
  return true;
}

pso::Slnp nth_to_last_linked_list(pso::Slnp x, int n) {
  pso::Slnp y = x;
  int i = 0;
  while (y != nullptr && i < n) {
    y = y->next;
    ++i;
  }
  if (y == nullptr) {
    return nullptr;
  }
  while (y != nullptr) {
    y = y->next;
    x = x->next;
  }
  return x;
}

bool is_permutation(const std::string &s1, const std::string &s2) {
  return false;
}

void replace_spaces(std::string &s) {}

bool is_palindrome(pso::Slnp head) {}
} // namespace pso::misc
