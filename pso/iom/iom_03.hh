#pragma once

#include <algorithm>
#include <string>
#include <tuple>
#include <vector>

#include "isa/lia/matrix.hh"

namespace pso::iom::t_03 {
struct A_max_mult {
  struct Res {
    int x1, x2, x3;
    Res(int x1_, int x2_, int x3_) : x1(x1_), x2(x2_), x3(x3_) {}
  };

  Res run(const std::vector<int> &v) {
    const int l = 30000;

    int mx1, mx2, mx3;
    mx1 = mx2 = mx3 = -l;

    int mn1, mn2, mn3;
    mn1 = mn2 = mn3 = l;

    const std::size_t n = v.size();

    bool all_pos = true;
    bool all_neg = true;

    for (std::size_t i = 0; i < n; ++i) {
      int e = v[i];
      if (e > mx1) {
        mx3 = mx2;
        mx2 = mx1;
        mx1 = e;
      } else if (e > mx2) {
        mx3 = mx2;
        mx2 = e;
      }

      if (e < mn1) {
        mn3 = mn2;
        mn2 = mn1;
        mn1 = e;
      } else if (e < mn2) {
        mn3 = mn2;
        mn2 = e;
      }

      if (e < 0) {
        all_pos = false;
      }
      if (e > 0) {
        all_neg = false;
      }
    }

    if (all_pos || all_neg) {
      return Res(mx1, mx2, mx3);
    }
    if (mx2 * mx3 > mn1 * mn2) {
      return Res(mx1, mx2, mx3);
    }
    return Res(mx1, mn2, mn1);
  }
};

struct d_square {
  isa::lia::Matrix<int> run(int n, int k, int s) {
    isa::lia::Matrix<int> res(n, n, 0);

    isa::lia::Matrix<int> sub(k, k, 0);

    int ones = 0;

    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < k; ++j) {
        if (ones < s) {
          sub(i, j) = 1;
          ++ones;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        res(i, j) = sub(i % k, j % k);
      }
    }

    return res;
  }
};

struct e_wheel_of_fortune {
  int run(std::vector<int> nums) { return 0; }
};
} // namespace pso::iom::t_03
