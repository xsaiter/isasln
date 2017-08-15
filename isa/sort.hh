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
}
}
