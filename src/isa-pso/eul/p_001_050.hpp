#pragma once

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

#include "ar/ar.hpp"

namespace pso::eul::p_001_050 {
struct P_001 {
  int run() {
    const int n = 1000;
    int res = 0;
    for (auto i = 3; i < n; ++i) {
      if (i % 3 == 0 || i % 5 == 0) {
        res += i;
      }
    }
    return res;
  }
};

struct P_002 {
  using T = unsigned int;
  T run() {
    T x = 1;
    T y = 2;
    T res = y;
    while (y < 4000000) {
      x += y;
      y += x;
      res += y;
    }
    return res;
  }
};

struct P_003 {
  std::size_t run() {}
};

struct P_004 {
  void run() {}
};

struct P_010 {
  using T = unsigned long;
  T run() {
    using PN = isa::ar::Is_prime_nums<T>;
    PN nums(0, 2000000);
    auto res = std::accumulate<PN::Iterator, T>(nums.begin(), nums.end(), 0);
    return res;
  }
};

struct P_015 {
  using T = unsigned int;
  template <T n> T run() {
    T res = 0;
    T a[n][n]{0};
    a[0][0] = 1;
    for (T i = 0; i < n; ++i) {
      for (T j = 0; j < n; ++j) {
        if (i > 0) {
          a[i][j] += a[i - 1][j];
        }
        if (j > 0) {
          a[i][j] += a[i][j - 1];
        }
      }
    }
    return a[n - 1][n - 1];
  }
};
} // namespace pso::eul::p_001_050
