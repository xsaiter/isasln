#pragma once

#include <string>

#include "geo/geo.hh"

namespace msh {
double t_11_d_circarea(const isa::geo::circle_s<double> &c1,
                       const isa::geo::circle_s<double> &c2);
}
