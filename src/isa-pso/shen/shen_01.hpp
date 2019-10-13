#pragma once

#include <string>
#include <vector>

#include "../core.hpp"

namespace pso::shen::t_01 {
struct T_01_01_01 {
  void run() {
    auto a = 1;
    auto b = 2;
    auto t = a;
    a = b;
    b = t;
  }
};

struct T_01_01_02 {
  void run() {
    auto a = 1;
    auto b = 2;
    a += b;
    b = a - b;
    a -= b;
  }
};

struct T_01_01_03 {
  void run() {
    int a = 1;
    int b = 2;
    std::string s;
  }
};

struct T_01_02_09 {
  template <int n, int m> int run(bool a[n][m]) {
    int res = 0;
    bool state = false;
    for (auto i = 1; i <= n; ++i) {
      for (auto j = 0; j < m; ++j) {
        if ((i < n && !a[i][j]) || i == n) {
          if (a[i - 1][j]) {
            state = true;
          }
          if (state && (!a[i - 1][j] || j == m - 1)) {
            ++res;
            state = false;
          }
        }
      }
    }
    return res;
  }
};

struct T_01_02_28 {
  template <int n, int m> std::tuple<int, int> run(int a[n][m], int x) {
    int l = 0;
    int r = n - 1;
    int k = -1;

    while (l <= r) {
      k = l + (r - l) / 2;
      auto p = a[0][k];
      auto q = a[n - 1][k];
      if (p == x) {
        return std::tuple(0, k);
      }
      if (q == x) {
        return std::tuple(n - 1, k);
      }
      if (x > p && x < q) {
        break;
      } else if (x > q) {
        l = k + 1;
      } else if (x < p) {
        r = k - 1;
      }
    }

    if (l <= r && k != -1) {
      l = 0;
      r = m - 1;
      while (l <= r) {
        auto t = l + (r - l) / 2;
        if (a[k][t] == x) {
          return std::tuple(l, r);
        }
        if (a[k][t] < x) {
          l = t + 1;
        } else {
          r = t - 1;
        }
      }
    }

    return std::tuple(-1, -1);
  }
};
} // namespace pso::shen::t_01
