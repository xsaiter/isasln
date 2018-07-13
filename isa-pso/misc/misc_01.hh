#pragma once

#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

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
}
