#pragma once

#include <vector>
#include <algorithm>

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

using range_i_u = range_s<int>;

template <typename T> using ranges_u = std::vector<range_s<T>>;

using ranges_i_u = ranges_u<int>;

template <typename T> ranges_u<T> recude_ranges(const ranges_u<T> &ranges) {
  struct entry_s {
    T x;
    bool is_left;
  };

  std::vector<entry_s> v;

  for (const auto &r : ranges) {
    v.push_back({r.l, true});
    v.push_back({r.r, false});
  }

  std::sort(v.begin(), v.end(),
            [](const auto &e1, const auto &e2) { return e1.x < e2.x; });

  ranges_u<T> res;

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
ranges_u<T> insert_range(const ranges_u<T> &ranges, const range_s<T> &x) {
  ranges_u<T> res;

  range_s<T> r = x;

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
