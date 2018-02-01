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

bool is_point_on_segment(const segment_s &s, const point_s &p);

bool segments_intersect(const segment_s &s1, const segment_s &s2);

bool circles_intersect(const circle_s &c1, const circle_s &c2);
}
}
