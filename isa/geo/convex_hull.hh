#pragma once

#include <algorithm>
#include <stack>
#include <vector>

#include "geo.hh"

namespace isa::geo {
template <typename T>
std::stack<point_s<T>> graham_scan(std::vector<point_s<T>> points) {
  const std::size_t n = points.size();

  std::stack<point_s<T>> hull;

  if (n < 4) {
    for (auto &i : points) {
      hull.push(i);
    }
    return hull;
  }

  unsigned min_y_pos = 0;
  int min_y = points[0].y;

  for (unsigned i = 1; i < n; ++i) {
    if (points[i].y < min_y) {
      min_y = points[i].y;
      min_y_pos = i;
    }
  }

  std::swap(points[0], points[min_y_pos]);

  auto pivot = points[0];

  auto beg = points.begin();

  std::advance(beg, 1);

  std::sort(beg, points.end(), [&](const point_s<T> &p1, const point_s<T> &p2) {
    T r = cross_product(pivot, p1, p2);
    if (r == 0) {
      auto d1 = distance2(pivot, p1);
      auto d2 = distance2(pivot, p2);
      return d1 > d2;
    }
    return r > 0;
  });

  hull.push(points[0]);
  hull.push(points[1]);
  hull.push(points[2]);

  for (unsigned i = 3; i < n; ++i) {
    while (true) {
      auto top = hull.top();
      hull.pop();
      auto next_top = hull.top();
      hull.push(top);

      if (cross_product(next_top, top, points[i]) == -1) {
        hull.pop();
      } else {
        hull.push(points[i]);
        break;
      }
    }
  }

  return hull;
}
} // namespace isa::geo
