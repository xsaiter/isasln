// dynamic prog

#pragma once

#include <array>
#include <string>
#include <vector>

#include "isa/common.hpp"
#include "isa/lia/matrix.hpp"

#define NOMINMAX

namespace pso::dynp {
int add_least_to_palindrome(const std::string &s);
int house_robber(const std::vector<int> &a);
int max_common_sequence(const std::string &s1, const std::string &s2);

struct Subarray_with_max_sum_res {
  int beg, end, sum;
};

void find_subarray_with_max_sum(const std::vector<int> &a,
                                Subarray_with_max_sum_res &res);

struct Turtle_travel_res {
  struct Cell {
    int x, y, val;
    Cell(int x_, int y_, int val_) : x(x_), y(y_), val(val_) {}
  };

  int sum;
  std::vector<Cell> path;
};

void turtle_travel(const std::vector<std::vector<int>> &a, int rows, int cols,
                   Turtle_travel_res &res);

struct Largest_square_res {
  int bottom_right_row;
  int bottom_right_col;
  int side;
};

void largest_square(const std::vector<std::vector<int>> &a, int rows, int cols,
                    Largest_square_res &res);

static int find(const std::string &s, int i, int j) {
  if (i >= j) {
    return 0;
  }
  if (s[i] == s[j]) {
    return find(s, i + 1, j - 1);
  } else {
    return std::min(find(s, i + 1, j), find(s, i, j - 1)) + 1;
  }
}

int add_least_to_palindrome(const std::string &s) {
  return find(s, 0, s.length() - 1);
}

int house_robber(const std::vector<int> &a) {
  const std::size_t n = a.size();

  if (n == 0) {
    return 0;
  }

  if (n == 1) {
    return a[0];
  }

  std::vector<int> b(n);

  b[0] = a[0];
  b[1] = std::max(a[0], a[1]);

  for (std::size_t i = 2; i < n; ++i) {
    b[i] = std::max(b[i - 2] + a[i], b[i - 1]);
  }

  return b[n - 1];
}

std::size_t levenshtein_distance(const std::string &from,
                                 const std::string &to) {
  std::size_t n = from.size();
  std::size_t m = to.size();
  isa::lia::Matrix<std::size_t> d(n, m, 0);
  for (std::size_t i = 0; i < n; ++i) {
    for (std::size_t j = 0; j < m; ++j) {
      if (i == 0 && j == 0) {
        d(i, j) = 0;
      } else if (i == 0 && j > 0) {
        d(i, j) = j;
      } else if (i > 0 && j == 0) {
        d(i, j) = i;
      } else {
        auto p = d(i, j - 1) + 1;
        auto q = d(i - 1, j) + 1;
        auto r = d(i - 1, j - 1) + ((from[i - 1] == to[j - 1]) ? 0 : 1);
        auto smallest = p;
        if (q < smallest) {
          smallest = q;
        }
        if (r < smallest) {
          smallest = r;
        }
        d(i, j) = smallest;
      }
    }
  }
  return d(n - 1, m - 1);
}

template <typename T> using Mat = std::vector<std::vector<T>>;
using S = std::size_t;

template <typename T> Mat<T> new_mat(S rows, S cols, T initial) {
  Mat<T> res;
  res.resize(rows, std::vector<T>(cols, initial));
  return res;
}

int max_common_sequence(const std::string &s1, const std::string &s2) {
  const S n1 = s1.size();
  const S n2 = s2.size();

  std::vector<std::vector<int>> b;
  b.resize(n1, std::vector<int>(n2, 0));

  std::vector<std::vector<bool>> a;
  a.resize(n1, std::vector<bool>(n2, false));

  bool first = false;
  for (S i = 0; i < n1; ++i) {
    if (first) {
      b[i][0] = 1;
    } else {
      if (s1[i] == s2[0]) {
        b[i][0] = 1;
        a[i][0] = true;
        first = true;
      } else {
        b[i][0] = 0;
      }
    }
  }

  first = false;
  for (S j = 0; j < n2; ++j) {
    if (first) {
      b[0][j] = 1;
    } else {
      if (s1[0] == s2[j]) {
        b[0][j] = 1;
        a[0][j] = true;
        first = true;
      } else {
        b[0][j] = 0;
      }
    }
  }

  for (S i = 0; i < n1; ++i) {
    for (S j = 0; j < n2; ++j) {
      if (s1[i] == s2[j]) {
        a[i][j] = true;
      }
    }
  }

  for (S i = 1; i < n1; ++i) {
    for (S j = 1; j < n2; ++j) {
      int m = std::max(b[i - 1][j], b[i][j - 1]);
      if (a[i][j]) {
        m = std::max(m, b[i - 1][j - 1] + 1);
      }
      b[i][j] = m;
    }
  }

  return b[n1 - 1][n2 - 1];
}

void find_subarray_with_max_sum(const std::vector<int> &a,
                                Subarray_with_max_sum_res &res) {
  const int n = a.size();

  int beg = 0;
  int end = 0;

  int cur = a[beg];
  int prev = cur;
  int sum = cur;

  bool flag = false;

  for (int i = 1; i < n; ++i) {
    if (a[i] > prev + a[i]) {
      flag = true;
      cur = a[i];
    } else {
      cur = prev + a[i];
    }

    prev = cur;

    if (cur > sum) {
      sum = cur;
      end = i;
      if (flag) {
        beg = i;
        flag = false;
      }
    }
  }

  res.beg = beg;
  res.end = end;
  res.sum = sum;
}

void turtle_travel(const std::vector<std::vector<int>> &a, int rows, int cols,
                   Turtle_travel_res &res) {
  std::vector<std::vector<int>> b;
  b.resize(rows, std::vector<int>(cols, 0));
  int i, j;

  for (i = rows - 1; i >= 0; --i) {
    for (j = 0; j <= cols - 1; ++j) {
      if (i == rows - 1 && j == 0) {
        b[i][j] = a[i][j];
      } else if (j == 0) {
        b[i][j] = a[i][j] + b[i + 1][j];
      } else if (i == rows - 1) {
        b[i][j] = a[i][j] + b[i][j - 1];
      } else {
        b[i][j] = a[i][j] + std::max(b[i + 1][j], b[i][j - 1]);
      }
    }
  }

  res.sum = b[0][cols - 1];

  i = rows - 1;
  j = 0;

  res.path.push_back(Turtle_travel_res::Cell(i, j, a[i][j]));

  while (i != 0 || j != cols - 1) {
    if (i == 0) {
      ++j;
    } else if (j == cols - 1) {
      --i;
    } else if (b[i - 1][j] < b[i][j + 1]) {
      ++j;
    } else {
      --i;
    }

    res.path.push_back(Turtle_travel_res::Cell(i, j, a[i][j]));
  }
}

void largest_square(const std::vector<std::vector<int>> &a, int rows, int cols,
                    Largest_square_res &res) {
  std::vector<std::vector<int>> b;
  b.resize(rows, std::vector<int>(cols, 0));

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (i == 0 || j == 0) {
        b[i][j] = a[i][j];
      } else {
        if (a[i][j] == 0) {
          b[i][j] = 0;
        } else {
          b[i][j] = isa::min_of(b[i - 1][j], b[i][j - 1], b[i - 1][j - 1]) + 1;
        }
      }
    }
  }

  int side = 0;
  int r = 0;
  int c = 0;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (b[i][j] > side) {
        side = b[i][j];
        r = i;
        c = j;
      }
    }
  }

  res.bottom_right_row = r;
  res.bottom_right_col = c;
  res.side = side;
}
} // namespace pso::dynp
