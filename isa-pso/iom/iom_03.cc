#pragma once

#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

#include "iom_03.hh"

namespace iom {
max_mult_res_s iom_03_a_max_mult(const std::vector<int> &v) {
  const int l = 30000;

  int mx1, mx2, mx3;
  mx1 = mx2 = mx3 = -l;

  int mn1, mn2, mn3;
  mn1 = mn2 = mn3 = l;

  const int n = v.size();

  bool all_pos = true;
  bool all_neg = true;

  for (int i = 0; i < n; ++i) {
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
    return max_mult_res_s(mx1, mx2, mx3);
  }

  if (mx2 * mx3 > mn1 * mn2) {
    return max_mult_res_s(mx1, mx2, mx3);
  }

  return max_mult_res_s(mx1, mn2, mn1);
}

isa::lia::matrix_s<int> iom_03_d_square(int n, int k, int s) {
  isa::lia::matrix_s<int> res(n, n, 0);

  isa::lia::matrix_s<int> sub(k, k, 0);

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

int iom_03_e_wheel_of_fortune(std::vector<int> nums) { return 0; }
}
