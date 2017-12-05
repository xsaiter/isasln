#include "t_02.hh"

#include "geo/geo.hh"

namespace tss {
namespace msh {

bool t_02_d_segments(const isa::geo::segment_s &s1,
                     const isa::geo::segment_s &s2) {
  return isa::geo::segments_intersect(s1, s2);
}
}
}
