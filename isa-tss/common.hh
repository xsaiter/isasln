#pragma once

namespace tss {
struct point_s {
  int x, y;
};

/*
  > 0 if a, b, c - clockwise
  < 0 - counterclockwise
  = 0 - collinear
*/
int cross_product(const point_s &a, const point_s &b, const point_s &c);
}
