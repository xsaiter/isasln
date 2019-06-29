#include <cmath>

#include "ar.hh"

namespace isa::ar {
std::vector<std::size_t> sieve_of_erat(std::size_t n) {
  std::vector<std::size_t> a(n);
  std::vector<bool> b(n);
  std::size_t i;
  for (i = 0; i < n; ++i) {
    a[i] = i + 2;
    b[i] = false;
  }
  i = 0;
  std::size_t pos = 0;
  while (i < n) {
    std::size_t v = a[pos];
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
  std::vector<std::size_t> res;
  for (i = 0; i < n; ++i) {
    if (!b[i]) {
      res.push_back(a[i]);
    }
  }
  return res;
}

std::size_t num_digits(std::size_t n) {
  std::size_t res = 0;
  do {
    n = n / 10;
    ++res;
  } while (n != 0);

  return res;
}

bool is_perfect_num(std::size_t n) {
  std::size_t s = 0;
  std::size_t m = static_cast<std::size_t>(std::ceil(std::sqrt(n)));
  for (std::size_t i = 1; i <= m; ++i) {
    if (n % i == 0) {
      s += i;
      if (i > 1) {
        s += n / i;
      }
    }
  }
  return s == n;
}

std::size_t fact(std::size_t n) {
  std::size_t res = 1;
  if (n > 1) {
    for (std::size_t i = 2; i <= n; ++i) {
      res *= i;
    }
  }
  return res;
}
} // namespace isa::ar
