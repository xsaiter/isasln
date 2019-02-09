#include "numeric.hh"
#include <cmath>

namespace isa {
std::vector<int> sieve_of_erat(int n) {
  std::vector<int> a(n);
  std::vector<bool> b(n);

  int i;
  for (i = 0; i < n; ++i) {
    a[i] = i + 2;
    b[i] = false;
  }

  i = 0;

  int pos = 0;
  while (i < n) {
    int v = a[pos];
    for (i = v * v - 2; i < n; i += v) {
      b[i] = true;
    }
    for (i = pos + 1; i < n; ++i) {
      if (!b[i]) {
        pos = i;
        break;
      }
    }
  }

  std::vector<int> res;

  for (i = 0; i < n; ++i) {
    if (!b[i]) {
      res.push_back(a[i]);
    }
  }

  return res;
}

int num_digits(int n) {
  int digits = 0;

  do {
    n = n / 10;
    ++digits;
  } while (n != 0);

  return digits;
}

bool is_perfect_num(int n) {
  int s = 0;

  auto m = static_cast<int>(std::ceil(std::sqrt(n)));

  for (int i = 1; i <= m; ++i) {
    if (n % i == 0) {
      s += i;
      if (i > 1) {
        s += n / i;
      }
    }
  }

  return s == n;
}

int fact(int n) {
  int res = 1;
  if (n > 1) {
    for (auto i = 2; i <= n; ++i) {
      res *= i;
    }
  }
  return res;
}
}
