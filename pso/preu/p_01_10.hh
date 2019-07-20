#pragma once

#include <string>
#include <vector>

namespace pso::preu {
struct P_01 {
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

struct P_02 {};

struct P_03 {
  std::size_t run() {}
};

struct P_04 {
  void run() {}
};
} // namespace pso::preu
