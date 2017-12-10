#include "vlong.hh"

namespace isa {
vlong_s::vlong_s(const std::string &s, unsigned int sys) : s_(s), sys_(sys) {}

vlong_s operator+(const vlong_s &lhs, const vlong_s &rhs) { return lhs; }

vlong_s operator-(const vlong_s &lhs, const vlong_s &rhs) { return rhs; }
}
