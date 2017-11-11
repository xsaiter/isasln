#include "t_02.hh"

#include <algorithm>

#include "common.hh"

namespace tss {
namespace msh {

static bool is_point_on_segment(const isa::geo::segment_s &s,
                                const isa::geo::point_s &p) {
  return std::max(s.p1.x, s.p2.x) >= p.x >= std::min(s.p1.x, s.p2.x) &&
         std::max(s.p1.y, s.p2.y) >= p.y >= std::min(s.p1.y, s.p2.y);
}

bool t_02_d_segments(const isa::geo::segment_s &s1,
                     const isa::geo::segment_s &s2) {
  auto r1 = isa::geo::cross_product(s1.p1, s1.p2, s2.p1);
  auto r2 = isa::geo::cross_product(s1.p1, s1.p2, s2.p2);

  auto r3 = isa::geo::cross_product(s2.p1, s2.p2, s1.p1);
  auto r4 = isa::geo::cross_product(s2.p1, s2.p2, s1.p2);

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
