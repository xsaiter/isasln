#pragma once

#include <algorithm>

namespace isa {
namespace geo {

template <typename T> struct point_s { T x, y; };

template <typename T> point_s<T> make_point(const T &x, const T &y) {
  return point_s<T>{x, y};
}

template <typename T> struct segment_s { point_s<T> p1, p2; };

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

template <typename T>
bool circles_intersect(const circle_s<T> &c1, const circle_s<T> &c2) {
  return false;
}
}
}
