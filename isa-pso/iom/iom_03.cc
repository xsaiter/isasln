#pragma once

#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

#include "iom_03.hh"

namespace iom {
max_mult_res_s iom_04_a_max_mult(const std::vector<int> &v) {
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
}
