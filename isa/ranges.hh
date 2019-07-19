#pragma once

#include <algorithm>
#include <vector>

namespace isa {
template <typename T> struct Range {
  T l, r;
  Range(const T &l_, const T &r_) : l(l_), r(r_) {}
  Range() : l(0), r(0) {}
  friend bool operator==(const Range<T> &lhs, const Range<T> &rhs) {
    return lhs.l == rhs.l && lhs.r == rhs.r;
  }
  friend bool operator!=(const Range<T> &lhs, const Range<T> &rhs) {
    return !(lhs == rhs);
  }
};

using Range_i = Range<int>;
template <typename T> using Ranges = std::vector<Range<T>>;
using Ranges_i = Ranges<int>;

template <typename T> Ranges<T> recude_ranges(const Ranges<T> &ranges) {
  struct Entry {
    T x;
    bool is_left;
  };
  std::vector<Entry> v;
  for (const auto &r : ranges) {
    v.push_back({r.l, true});
    v.push_back({r.r, false});
  }
  auto cmp = [](const auto &a, const auto &b) { return a.x < b.x; };
  std::sort(v.begin(), v.end(), cmp);
  Ranges<T> res;
  int n = 0;
  T l;
  for (const auto &e : v) {
    if (e.is_left) {
      if (n == 0) {
        l = e.x;
      }
      ++n;
    } else {
      --n;
    }
    if (n > 0) {
    }
    if (n == 0) {
      res.push_back({l, e.x});
    }
  }
  return res;
}

template <typename T>
Range<T> merge_intersect_ranges(const Range<T> &a, const Range<T> &b) {
  if (a.l < b.l) {
    return a.r < b.r ? Range<T>(a.l, b.r) : Range<T>(a.l, a.r);
  }
  return a.r < b.r ? Range<T>(b.l, b.r) : Range<T>(b.l, a.r);
}

template <typename T>
bool intersect_ranges(const Range<T> &a, const Range<T> &b) {
  return (a.l >= b.l && a.l <= b.r) || (b.l >= a.l && b.l <= a.r);
}

template <typename T>
bool intersect_ranges(const Range<T> &a, const Range<T> &b, Range<T> &res) {
  if (a.l <= b.l && a.r >= b.l) {
    res = {b.l, std::min(a.r, b.r)};
    return true;
  }
  if (a.l >= b.l && a.l <= b.r) {
    res = {a.l, std::min(a.r, b.r)};
    return true;
  }
  return false;
}

template <typename T>
Ranges<T> insert_range(const Ranges<T> &ranges, const Range<T> &x) {
  Ranges<T> res;
  Range<T> r = x;
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
} // namespace isa
