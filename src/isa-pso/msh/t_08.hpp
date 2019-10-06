#pragma once

#include "isa/geo/geo.hpp"
#include <cmath>
#include <functional>
#include <numeric>

namespace pso::msh::t_08 {
struct A_nosum {
  int run(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    auto s = std::accumulate(nums.cbegin(), nums.cend(), 0);
    int k = 1;
    while (ok(k, nums)) {
      ++k;
    }
    return k;
  }

private:
  bool ok(int k, const std::vector<int> &nums) {
    auto n = static_cast<int>(nums.size());
    for (auto j = 0; j < n - 1; ++j) {
      auto s = 0;
      for (auto i = j; i < n; ++i) {
        if (k == nums[i]) {
          return true;
        }
        s += nums[i];
        if (s == k) {
          return true;
        }
        if (s > k) {
          break;
        }
      }
    }
    return false;
  }
};

struct D_sphera_arc {
  double run(double r, double lge_1, double lte_1, double lge_2, double lte_2) {
    double x1 = r * std::cos(lge_1) * std::cos(lte_1);
    double y1 = r * std::cos(lge_1) * std::sin(lte_1);
    double z1 = r * std::sin(lge_1);

    double x2 = r * std::cos(lge_2) * std::cos(lte_2);
    double y2 = r * std::cos(lge_2) * std::sin(lte_2);
    double z2 = r * std::sin(lge_2);

    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;

    double d = std::sqrt(dx * dx + dy * dy + dz * dz);
    auto a = 2 * std::asin(d / (2 * r));
    auto res = 2 * 3.14 * r * a / 360;
    return res;
  }
};
} // namespace pso::msh::t_08
