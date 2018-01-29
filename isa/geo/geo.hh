#pragma once

namespace isa {
namespace geo {

template <typename T = double> struct point_s { T x, y; };

using point_u = point_s<>;

struct segment_s {
  point_u p1;
  point_u p2;
};

struct circle_s {
  double x, y, r;
};

/*
  > 0 if a, b, c - clockwise
  < 0 - counterclockwise
  = 0 - collinear
*/
double cross_product(const point_u &a, const point_u &b, const point_u &c);

int distance2(const point_u &a, const point_u &b);

bool is_point_on_segment(const segment_s &s, const point_u &p);

bool segments_intersect(const segment_s &s1, const segment_s &s2);
}
}
