#include "vlong.hh"

namespace isa {
vlong_s::vlong_s(std::string s, unsigned int sys) : s_(s), sys_(sys) {}

vlong_s operator+(const vlong_s &x, const vlong_s &y) { return x; }

vlong_s operator-(const vlong_s &x, const vlong_s &y) { return x; }
}
