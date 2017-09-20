#pragma once

#include <algorithm>
#include <memory>

namespace isa {
namespace sorting {

template <typename Iterator,
          typename Compare =
              std::less<typename std::iterator_traits<Iterator>::value_type>>
class merge_sort_s {
public:
  static void sort(Iterator beg, Iterator end, Compare cmp = Compare()) {
    const std::size_t n = std::distance(beg, end);

    int step = 2;
    int diff = 1;

    while (step < 2 * n) {
      Iterator i = beg;
      while (i != end) {
        Iterator mid;
        Iterator cend;

        int x = std::distance(beg, i) + step;

        if (x <= n) {
          cend = std::next(i, step);
          mid = std::next(i, distance(i, cend) / 2);
        } else {
          cend = end;
          mid = std::prev(cend, diff);
          diff = std::distance(i, cend);
        }

        merge(i, mid, cend, cmp);

        if (next(i) == end || step > n) {
          break;
        }

        x = std::distance(beg, i) + step;
        if (x > n) {
          break;
        }

        i = std::next(i, step);
      }
      step *= 2;
    }
  }

private:
  static void merge(Iterator beg, Iterator mid, Iterator end, Compare cmp) {
    auto d = std::distance(beg, end);
    if (d == 1) {
      return;
    }

    if (d == 2) {
      if (*beg > *mid) {
        std::iter_swap(beg, mid);
      }
      return;
    }

    const int n1 = std::distance(beg, mid);
    const int n2 = std::distance(mid, end);
    const int len = n1 + n2;

    std::vector<int> vec(len);

    int p1 = 0, p2 = 0;

    while (p1 + p2 < len) {
      if (p1 == n1) {
        vec[p1 + p2] = *std::next(mid, p2);
        ++p2;
      } else if (p2 == n2) {
        vec[p1 + p2] = *std::next(beg, p1);
        ++p1;
      } else if (*std::next(beg, p1) > *std::next(mid, p2)) {
        vec[p1 + p2] = *std::next(mid, p2);
        ++p2;
      } else {
        vec[p1 + p2] = *std::next(beg, p1);
        ++p1;
      }
    }

    for (int i = 0; i < len; ++i) {
      *std::next(beg, i) = vec[i];
    }
  }
};
}
}
