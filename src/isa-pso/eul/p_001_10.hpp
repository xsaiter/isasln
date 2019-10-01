#pragma once

#include <string>
#include <vector>

namespace pso::eul::p_001_10 {
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
  int run() {}
};

struct P_003 {
  std::size_t run() {}
};

struct P_004 {
  void run() {}
};
}  // namespace pso::eul::p_001_10
