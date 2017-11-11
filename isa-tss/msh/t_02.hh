#pragma once

#include "geo/geo.hh"

namespace tss {
namespace msh {
void t_02_c_route(const isa::geo::segment_s &s1, const isa::geo::segment_s &s2);
bool t_02_d_segments(const isa::geo::segment_s &s1,
                     const isa::geo::segment_s &s2);
}
}
