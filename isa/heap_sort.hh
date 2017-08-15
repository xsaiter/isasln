#pragma once

#include <algorithm>
#include <memory>

namespace isa {
namespace sorting {

template <typename Iterator,
          typename Compare =
              std::less<typename std::iterator_traits<Iterator>::value_type>>
class heap_sort_t {
public:
  static void perform(Iterator beg, Iterator end, Compare cmp = Compare()) {
    heap_sort_t s(beg, end, cmp);
    s.sort();
  }

private:
  Iterator beg_;
  Iterator end_;
  Compare cmp_;

  heap_sort_t(Iterator beg, Iterator end, Compare cmp = Compare())
      : beg_(beg), end_(end), cmp_(cmp) {}
  heap_sort_t(const heap_sort_t &) = delete;
  heap_sort_t &operator=(const heap_sort_t &) = delete;

  void sort() {
    build_heap();

    Iterator cur = end_;

    for (auto i = std::prev(end_); i != beg_; --i) {
      std::swap(*beg_, *i);
      cur = std::prev(cur);
      down_heap(cur, beg_);
    }
  }

  void build_heap() {
    int n = std::distance(beg_, end_);
    int ss;

    if (n % 2 == 0) {
      ss = n / 2;
    } else {
      ss = (n + 1) / 2;
    }

    Iterator mid = std::next(beg_, ss);
    mid = std::prev(mid);

    for (Iterator i = mid; i != beg_; --i) {
      down_heap(end_, i);
    }

    down_heap(end_, beg_);
  }

  void down_heap(Iterator n, Iterator i) {
    int di = std::distance(beg_, i);
    int dn = std::distance(beg_, n);

    Iterator p = i;

    if (2 * di < dn) {
      Iterator p1 = std::next(beg_, 2 * di);
      if (*p1 > *i) {
        p = p1;
      }
    }

    if (2 * di + 1 < dn) {
      Iterator p2 = std::next(beg_, 2 * di + 1);
      if (*p2 > *p) {
        p = p2;
      }
    }

    if (p != i) {
      std::iter_swap(p, i);
      down_heap(n, p);
    }
  }
};
}
}
