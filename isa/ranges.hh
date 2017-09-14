#pragma once

#include <vector>

namespace isa {
template <class T> struct range_s {
  T beg, end;
  range_s(const T &beg_, const T &end_) : beg(beg_), end(end_) {}
};

template <class T>
bool operator==(const range_s<T> &lhs, const range_s<T> &rhs) {
  return lhs.beg == rhs.beg && lhs.end == rhs.end;
}

template <class T>
bool operator!=(const range_s<T> &lhs, const range_s<T> &rhs) {
  return !(lhs == rhs);
}

template <class T>
range_s<T> merge_intersect_ranges(const range_s<T> &a, const range_s<T> &b) {
  if (a.beg < b.beg) {
    if (a.end < b.end) {
      return range_s<T>(a.beg, b.end);
    }
    return range_s<T>(a.beg, a.end);
  } else {
    if (a.end < b.end) {
      return range_s<T>(b.beg, b.end);
    }
    return range_s<T>(b.beg, a.end);
  }
}

template <class T>
bool intersect_ranges(const range_s<T> &a, const range_s<T> &b) {
  return (a.beg >= b.beg && a.beg <= b.end) ||
         (b.beg >= a.beg && b.beg <= a.end);
}

template <class T>
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
