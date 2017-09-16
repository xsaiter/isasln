#include <array>

#include "dynp.hh"

namespace dynp {

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

int levenshtein_distance(const std::string &from, const std::string &to) {
  const int n = from.size();
  const int m = to.size();

  int d[n][m] = {0};

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == 0 && j == 0) {
        d[i][j] = 0;
      } else if (i == 0 && j > 0) {
        d[i][j] = j;
      } else if (i > 0 && j == 0) {
        d[i][j] = i;
      } else {
        int p = d[i][j - 1] + 1;
        int q = d[i - 1][j] + 1;
        int r = d[i - 1][j - 1] + ((from[i - 1] == to[j - 1]) ? 0 : 1);
        int smallest = p;
        if (q < smallest) {
          smallest = q;
        }

        if (r < smallest) {
          smallest = r;
        }

        d[i][j] = smallest;
      }
    }
  }

  return d[n - 1][m - 1];
}

int max_common_sequence(const std::string &s1, const std::string &s2) {
  const int n1 = s1.size();
  const int n2 = s2.size();

  int b[n1][n2];
  bool a[n1][n2];

  bool first = false;
  for (int i = 0; i < n1; ++i) {
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
  for (int j = 0; j < n2; ++j) {
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

  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < n2; ++j) {
      if (s1[i] == s2[j]) {
        a[i][j] = true;
      }
    }
  }

  for (int i = 1; i < n1; ++i) {
    for (int j = 1; j < n2; ++j) {
      int m = std::max(b[i - 1][j], b[i][j - 1]);
      if (a[i][j]) {
        m = std::max(m, b[i - 1][j - 1] + 1);
      }
      b[i][j] = m;
    }
  }

  return b[n1 - 1][n2 - 1];
}

void subarray_with_max_sum(const std::vector<int> &a,
                           subarray_with_max_sum_res_s &res) {
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
                   turtle_travel_res_s &res) {
  int b[rows][cols];
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

  res.path.push_back(turtle_travel_res_s::cell_s(i, j, a[i][j]));

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

    res.path.push_back(turtle_travel_res_s::cell_s(i, j, a[i][j]));
  }
}

static int min(int a, int b, int c) { return std::min(std::min(a, b), c); }

void largest_square(const std::vector<std::vector<int>> &a, int rows, int cols,
                    largest_square_res_s &res) {
  int b[rows][cols];

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (i == 0 || j == 0) {
        b[i][j] = a[i][j];
      } else {
        if (a[i][j] == 0) {
          b[i][j] = 0;
        } else {
          b[i][j] = min(b[i - 1][j], b[i][j - 1], b[i - 1][j - 1]) + 1;
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

  res.bottomRightRow = r;
  res.bottomRightCol = c;
  res.side = side;
}
}
