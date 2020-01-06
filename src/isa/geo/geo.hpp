#pragma once

#include <algorithm>
#include <cmath>

#include "../ranges.hpp"

namespace isa::geo {
template <typename T> struct Point { T x, y; };

template <typename T> Point<T> make_point(const T &x, const T &y) {
  return Point<T>{x, y};
}

template <typename T> struct Segment { Point<T> p1, p2; };

template <typename T> struct Rect {
  Point<T> lhs_bottom;
  Point<T> rhs_top;

  T area() const {
    return (lhs_bottom.x - rhs_top.x) * (lhs_bottom.y - rhs_top.y);
  }
};

template <typename T>
T area_intersection_of_rects(const std::vector<Rect<T>> &rects) {
  auto n = rects.size();
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return rects[0].area();
  }
  auto curx = Range<T>{rects[0].lhs_bottom.x, rects[0].rhs_top.x};
  for (unsigned long i = 1; i < n; ++i) {
    if (!intersect_ranges(curx, {rects[i].lhs_bottom.x, rects[i].rhs_top.x},
                          curx)) {
      return 0;
    }
  }
  auto cury = Range<T>{rects[0].lhs_bottom.y, rects[0].rhs_top.y};
  for (unsigned long i = 1; i < n; ++i) {
    if (!intersect_ranges(cury, {rects[i].lhs_bottom.y, rects[i].rhs_top.y},
                          cury)) {
      return 0;
    }
  }
  return (curx.r - curx.l) * (cury.r - cury.l);
}

template <typename T>
Segment<T> make_segment(const Point<T> &p1, const Point<T> &p2) {
  return Segment<T>{p1, p2};
}

template <typename T> struct Circle { T x, y, r; };

template <typename T>
Circle<T> make_circle(const T &x, const T &y, const T &r) {
  return Circle<T>{x, y, r};
}

enum class Orientations { Clockwise, Counterclockwise, Collinear };

/*
  > 0 if a, b, c - clockwise
  < 0 - counterclockwise
  = 0 - collinear
*/
template <typename T>
T cross_product(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

template <typename T, typename Compare>
Orientations orientation(const Point<T> &a, const Point<T> &b,
                         const Point<T> &c, Compare compare) {
  auto r = cross_product(a, b, c);
  auto x = compare(r, 0);
  return x == 0 ? Orientations::Collinear
                : (x > 0 ? Orientations::Clockwise
                         : Orientations::Counterclockwise);
}

template <typename T> T distance2(const Point<T> &a, const Point<T> &b) {
  auto dx = a.x - b.x;
  auto dy = a.y - b.y;
  return dx * dx + dy * dy;
}

template <typename T>
bool is_point_on_segment(const Segment<T> &s, const Point<T> &p) {
  return std::max(s.p1.x, s.p2.x) >= p.x && p.x >= std::min(s.p1.x, s.p2.x) &&
         std::max(s.p1.y, s.p2.y) >= p.y && p.y >= std::min(s.p1.y, s.p2.y);
}

template <typename T>
bool segments_intersect(const Segment<T> &s1, const Segment<T> &s2) {
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

bool circles_intersect(const Circle<double> &c1, const Circle<double> &c2) {
  auto p = c1.x - c2.x;
  auto q = c1.y - c2.y;
  auto dist = std::sqrt(p * p + q * q);
  return dist < c1.r + c2.r;
}
} // namespace isa::geo
