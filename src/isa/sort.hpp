#pragma once

#include <algorithm>
#include <memory>
#include <vector>

namespace isa::sorting {
template <typename It, typename Cmp = std::less<
                           typename std::iterator_traits<It>::value_type>>
void bubble_sort(It beg, It end, Cmp cmp = Cmp()) {
  for (It i = beg; i != end; ++i) {
    bool swapped = false;
    for (It j = beg + 1; j != end; ++j) {
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

template <typename It, typename Cmp = std::less<
                           typename std::iterator_traits<It>::value_type>>
void insertion_sort(It beg, It end, Cmp cmp = Cmp()) {
  for (It i = beg; i != end; ++i) {
    It j = i;
    while (j != beg && cmp(*j, *(j - 1))) {
      std::iter_swap(j, j - 1);
      --j;
    }
  }
}

template <typename It, typename Cmp = std::less<
                           typename std::iterator_traits<It>::value_type>>
void shell_sort(It beg, It end, Cmp cmp = Cmp()) {
  int n = std::distance(beg, end);
  for (int d = n / 2; d >= 1; d /= 2) {
    It i = beg;
    while (i != end) {
      It j = i;
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

template <typename It, typename Cmp = std::less<
                           typename std::iterator_traits<It>::value_type>>
void selection_sort(It beg, It end, Cmp cmp = Cmp()) {
  for (It i = beg; i != end; ++i) {
    It pos = i;
    for (It j = i; j != end; ++j) {
      if (cmp(*j, *pos)) {
        pos = j;
      }
    }
    if (pos != i) {
      std::iter_swap(pos, i);
    }
  }
}

template <typename It, typename Cmp = std::less<
                           typename std::iterator_traits<It>::value_type>>
void gnome_sort(It beg, It end, Cmp cmp = Cmp()) {
  It i = std::next(beg, 1);
  while (i != end) {
    if (i == beg || cmp(*i, *(i - 1))) {
      ++i;
    } else {
      std::iter_swap(i, i - 1);
      --i;
    }
  }
}

template <typename It,
          typename Cmp =
              std::less<typename std::iterator_traits<It>::value_type>>
class Heap_sort {
public:
  static void perform(It beg, It end, Cmp cmp = Cmp()) {
    Heap_sort s(beg, end, cmp);
    s.sort();
  }

private:
  It beg_;
  It end_;
  Cmp cmp_;

  Heap_sort(It beg, It end, Cmp cmp = Cmp())
      : beg_(beg), end_(end), cmp_(cmp) {}
  Heap_sort(const Heap_sort &) = delete;
  Heap_sort &operator=(const Heap_sort &) = delete;

  void sort() {
    build_heap();
    It cur = end_;
    for (auto i = std::prev(end_); i != beg_; --i) {
      std::swap(*beg_, *i);
      cur = std::prev(cur);
      down_heap(cur, beg_);
    }
  }

  void build_heap() {
    int n = std::distance(beg_, end_);
    int k;
    if (n % 2 == 0) {
      k = n / 2;
    } else {
      k = (n + 1) / 2;
    }
    auto mid = std::next(beg_, k);
    mid = std::prev(mid);
    for (auto i = mid; i != beg_; --i) {
      down_heap(end_, i);
    }
    down_heap(end_, beg_);
  }

  void down_heap(It n, It i) {
    int di = std::distance(beg_, i);
    int dn = std::distance(beg_, n);

    It p = i;

    if (2 * di < dn) {
      It p1 = std::next(beg_, 2 * di);
      if (*p1 > *i) {
        p = p1;
      }
    }

    if (2 * di + 1 < dn) {
      It p2 = std::next(beg_, 2 * di + 1);
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

template <typename It,
          typename Cmp =
              std::less<typename std::iterator_traits<It>::value_type>>
class Merge_sort {
public:
  static void sort(It beg, It end, Cmp cmp = Cmp()) {
    const std::size_t n = std::distance(beg, end);

    int step = 2;
    int diff = 1;

    while (step < 2 * n) {
      It i = beg;
      while (i != end) {
        It mid;
        It cend;

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
  static void merge(It beg, It mid, It end, Cmp cmp) {
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
} // namespace isa::sorting
