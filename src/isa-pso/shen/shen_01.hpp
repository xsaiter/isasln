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
} // namespace pso::shen::t_01
