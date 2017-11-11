#include "geo.hh"

namespace isa {
namespace geo {

int distance2(const point_s &a, const point_s &b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return dx * dx + dy * dy;
}

int cross_product(const point_s &a, const point_s &b, const point_s &c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
}
}
