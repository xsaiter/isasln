#pragma once

#include <algorithm>
#include <cmath>

#include "../ranges.hh"

namespace isa::geo {
template <typename T> struct point_s { T x, y; };

template <typename T> point_s<T> make_point(const T &x, const T &y) {
  return point_s<T>{x, y};
}

template <typename T> struct segment_s { point_s<T> p1, p2; };

template <typename T> struct rect_s {
  point_s<T> lhs_bottom;
  point_s<T> rhs_top;

  T area() const {
    return (lhs_bottom.x - rhs_top.x) * (lhs_bottom.y - rhs_top.y);
  }
};

template <typename T>
T area_intersection_of_rects(const std::vector<rect_s<T>> &rects) {
  auto n = rects.size();
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return rects[0].area();
  }
  auto curx = range_s<T>{rects[0].lhs_bottom.x, rects[0].rhs_top.x};
  for (unsigned long i = 1; i < n; ++i) {
    if (!intersect_ranges(curx, {rects[i].lhs_bottom.x, rects[i].rhs_top.x},
                          curx)) {
      return 0;
    }
  }
  auto cury = range_s<T>{rects[0].lhs_bottom.y, rects[0].rhs_top.y};
  for (unsigned long i = 1; i < n; ++i) {
    if (!intersect_ranges(cury, {rects[i].lhs_bottom.y, rects[i].rhs_top.y},
                          cury)) {
      return 0;
    }
  }
  return (curx.r - curx.l) * (cury.r - cury.l);
}

template <typename T>
T area_union_of_rects(const std::vector<rect_s<T>> &rects) {

  return 0;
}

template <typename T>
segment_s<T> make_segment(const point_s<T> &p1, const point_s<T> &p2) {
  return segment_s<T>{p1, p2};
}

template <typename T> struct circle_s { T x, y, r; };

template <typename T>
circle_s<T> make_circle(const T &x, const T &y, const T &r) {
  return circle_s<T>{x, y, r};
}

/*
  > 0 if a, b, c - clockwise
  < 0 - counterclockwise
  = 0 - collinear
*/
template <typename T>
T cross_product(const point_s<T> &a, const point_s<T> &b, const point_s<T> &c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

template <typename T> T distance2(const point_s<T> &a, const point_s<T> &b) {
  T dx = a.x - b.x;
  T dy = a.y - b.y;
  return dx * dx + dy * dy;
}

template <typename T>
bool is_point_on_segment(const segment_s<T> &s, const point_s<T> &p) {
  return std::max(s.p1.x, s.p2.x) >= p.x && p.x >= std::min(s.p1.x, s.p2.x) &&
         std::max(s.p1.y, s.p2.y) >= p.y && p.y >= std::min(s.p1.y, s.p2.y);
}

template <typename T>
bool segments_intersect(const segment_s<T> &s1, const segment_s<T> &s2) {
  auto r1 = cross_product(s1.p1, s1.p2, s2.p1);
  auto r2 = cross_product(s1.p1, s1.p2, s2.p2);

  auto r3 = cross_product(s2.p1, s2.p2, s1.p1);
  auto r4 = cross_product(s2.p1, s2.p2, s1.p2);

  if (((r1 > 0 && r2 < 0) || (r1 < 0 && r2 > 0)) &&
      ((r3 > 0 && r4 < 0) || (r3 < 0 && r4 > 0))) {
    return true;
  }

  if (r1 == 0) {
    return is_point_on_segment(s1, s2.p1);
  }

  if (r2 == 0) {
    return is_point_on_segment(s1, s2.p2);
  }

  if (r3 == 0) {
    return is_point_on_segment(s2, s1.p1);
  }

  if (r4 == 0) {
    return is_point_on_segment(s2, s1.p2);
  }

  return false;
}

bool circles_intersect(const circle_s<double> &c1, const circle_s<double> &c2) {
  auto p = c1.x - c2.x;
  auto q = c1.y - c2.y;
  auto dist = std::sqrt(p * p + q * q);
  return dist < c1.r + c2.r;
}
} // namespace isa::geo
