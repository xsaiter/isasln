#pragma once

#include <algorithm>
#include <memory>

namespace isa {
namespace sorting {

template <typename Iterator,
          typename Compare =
              std::less<typename std::iterator_traits<Iterator>::value_type>>
void bubble_sort(Iterator beg, Iterator end, Compare cmp = Compare()) {
  for (Iterator i = beg; i != end; ++i) {
    bool swapped = false;
    for (Iterator j = beg + 1; j != end; ++j) {
      if (cmp(*j, *(j - 1))) {
        std::iter_swap(j, j - 1);
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
  }
}

template <typename Iterator,
          typename Compare =
              std::less<typename std::iterator_traits<Iterator>::value_type>>
void insertion_sort(Iterator beg, Iterator end, Compare cmp = Compare()) {
  for (Iterator i = beg; i != end; ++i) {
    Iterator j = i;
    while (j != beg && cmp(*j, *(j - 1))) {
      std::iter_swap(j, j - 1);
      --j;
    }
  }
}

template <typename Iterator,
          typename Compare =
              std::less<typename std::iterator_traits<Iterator>::value_type>>
void shell_sort(Iterator beg, Iterator end, Compare cmp = Compare()) {
  int n = std::distance(beg, end);
  for (int d = n / 2; d >= 1; d /= 2) {
    Iterator i = beg;
    while (i != end) {
      Iterator j = i;
      while (j != beg && cmp(*j, *(j - 1))) {
        std::iter_swap(j, j - 1);
        j = std::prev(j, d);
      }

      if (std::distance(beg, i) + d > n) {
        break;
      }

      i = std::next(i, d);
    }
  }
}

template <typename Iterator,
          typename Compare =
              std::less<typename std::iterator_traits<Iterator>::value_type>>
void selection_sort(Iterator beg, Iterator end, Compare cmp = Compare()) {
  for (Iterator i = beg; i != end; ++i) {
    Iterator pos = i;
    for (Iterator j = i; j != end; ++j) {
      if (cmp(*j, *pos)) {
        pos = j;
      }
    }

    if (pos != i) {
      std::iter_swap(pos, i);
    }
  }
}

template <typename Iterator,
          typename Compare =
              std::less<typename std::iterator_traits<Iterator>::value_type>>
void gnome_sort(Iterator beg, Iterator end, Compare cmp = Compare()) {
  Iterator i = std::next(beg, 1);
  while (i != end) {
    if (i == beg || cmp(*i, *(i - 1))) {
      ++i;
    } else {
      std::iter_swap(i, i - 1);
      --i;
    }
  }
}

template <typename Iterator,
          typename Compare =
              std::less<typename std::iterator_traits<Iterator>::value_type>>
class heap_sort_s {
public:
  static void perform(Iterator beg, Iterator end, Compare cmp = Compare()) {
    heap_sort_s s(beg, end, cmp);
    s.sort();
  }

private:
  Iterator beg_;
  Iterator end_;
  Compare cmp_;

  heap_sort_s(Iterator beg, Iterator end, Compare cmp = Compare())
      : beg_(beg), end_(end), cmp_(cmp) {}
  heap_sort_s(const heap_sort_s &) = delete;
  heap_sort_s &operator=(const heap_sort_s &) = delete;

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
