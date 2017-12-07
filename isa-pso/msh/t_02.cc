#include <iostream>
#include <cstdio>

#include "common.hh"

#include "t_02.hh"

#include "geo/geo.hh"

namespace tss {
namespace msh {

bool t_02_d_segments(const isa::geo::segment_s &s1,
                     const isa::geo::segment_s &s2) {
  return isa::geo::segments_intersect(s1, s2);
}

void t_02_f_spiral(int n) {
  for (int i = 0; i < n; ++i) {
    std::printf("\n");
    for (int j = 0; j < n; ++j) {
      print_set_pos(i, j);
      std::printf(" %d", i * n + j);
    }
  }
}
}
}
