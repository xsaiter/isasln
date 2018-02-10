#include <cassert>
#include <vector>
#include "numeric.hh"

#include "t_04.hh"

namespace msh {

void t_04_a_perfect(int m, int n, std::vector<int> &res) {
  assert(m < n);
  for (int i = m; i <= n; ++i) {
    if (isa::is_perfect_num(i)) {
      res.push_back(i);
    }
  }
}

double t_04_d_area(const std::vector<isa::geo::point_s<int>> &points) {
  const int n = points.size();

  if (n < 2) {
    return 0;
  }

  double res = 0.0;

  for (int i = 1; i < n - 1; ++i) {
    res += isa::geo::cross_product(points[0], points[i], points[i + 1]) / 2.0;
  }

  return std::abs(res);
}
}
