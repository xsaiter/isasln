#include "common.hh"

namespace tss {
int cross_product(const point_s &a, const point_s &b, const point_s &c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
}
