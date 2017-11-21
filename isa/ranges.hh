#pragma once

#include <vector>

namespace isa {
template <typename T> struct range_s {
  T l, r;
  range_s(const T &l_, const T &r_) : l(l_), r(r_) {}

  friend bool operator==(const range_s<T> &lhs, const range_s<T> &rhs) {
    return lhs.l == rhs.l && lhs.r == rhs.r;
  }

  friend bool operator!=(const range_s<T> &lhs, const range_s<T> &rhs) {
    return !(lhs == rhs);
  }
};

using range_i_s = range_s<int>;

template <typename T>
range_s<T> merge_intersect_ranges(const range_s<T> &a, const range_s<T> &b) {
  if (a.l < b.l) {
    if (a.r < b.r) {
      return range_s<T>(a.l, b.r);
    }
    return range_s<T>(a.l, a.r);
  }

  if (a.r < b.r) {
    return range_s<T>(b.l, b.r);
  }
  return range_s<T>(b.l, a.r);
}

template <typename T>
bool intersect_ranges(const range_s<T> &a, const range_s<T> &b) {
  return (a.l >= b.l && a.l <= b.r) || (b.l >= a.l && b.l <= a.r);
}

template <typename T>
std::vector<range_s<T>> insert_range(const std::vector<range_s<T>> &ranges,
                                     const range_s<T> &range) {
  std::vector<range_s<T>> res;

  range_s<T> r = range;

  bool merged = false;

  for (const auto &cur : ranges) {
    if (intersect_ranges(cur, r)) {
      r = merge_intersect_ranges(cur, r);

      if (!merged) {
        res.push_back(r);
      } else {
        res.pop_back();
        res.push_back(r);
      }
      merged = true;
    } else {
      res.push_back(cur);
    }
  }

  if (!merged) {
    res.push_back(r);
  }

  return res;
}
}
