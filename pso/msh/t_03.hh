#pragma once

#include "isa/geo/geo.hh"
#include "pso/core.hh"

namespace pso::msh::t_03 {
std::vector<std::string> t_03_b_permutation(const std::string &s) {
  std::vector<std::string> res;

  return res;
}

bool t_03_d_postcard_and_envelope(const pso::whi_s &p, const pso::whi_s &e) {
  if (p.h <= e.h && p.w <= e.w) {
    return true;
  }
}
}
