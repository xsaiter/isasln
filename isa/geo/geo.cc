#include <algorithm>

#include "geo.hh"

namespace isa {
namespace geo {

int distance2(const point_s &a, const point_s &b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return dx * dx + dy * dy;
}

double cross_product(const point_s &a, const point_s &b, const point_s &c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool is_point_on_segment(const segment_s &s, const point_s &p) {
  return std::max(s.p1.x, s.p2.x) >= p.x && p.x >= std::min(s.p1.x, s.p2.x) &&
         std::max(s.p1.y, s.p2.y) >= p.y && p.y >= std::min(s.p1.y, s.p2.y);
}

bool segments_intersect(const segment_s &s1, const segment_s &s2) {
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
}
}
