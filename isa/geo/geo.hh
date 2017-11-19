#pragma once

namespace isa {
namespace geo {

struct point_s {
  double x, y;
};

struct segment_s {
  point_s p1;
  point_s p2;
};

struct circle_s {
  double x, y, r;
};

/*
  > 0 if a, b, c - clockwise
  < 0 - counterclockwise
  = 0 - collinear
*/
double cross_product(const point_s &a, const point_s &b, const point_s &c);

int distance2(const point_s &a, const point_s &b);
}
}
