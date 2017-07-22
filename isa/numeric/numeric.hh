#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>
#include <bitset>

namespace isa {
namespace numeric {

using namespace std;

template <class A, class B> A fast_pow(A a, B b) {
  if (b == 2) {
    return a * a;
  }

  A res;
  B r = b % 2;
  if (r == 0) {
    A t = fast_pow(a, b / 2);
    return t * t;
  } else {
    return a * fast_pow(a, b - 1);
  }

  return res;
}

template <class T> bool is_prime(T n) {
  for (T i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

template <class T> T gcd(T a, T b) {
  while (b != 0) {
    int c = a % b;
    a = b;
    b = c;
  }
  return (a > 0) ? a : -a;
}

template <class T> bool is_relatively_prime(T a, T b) { return gcd(a, b) == 1; }

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

template <std::size_t N> void inc(std::bitset<N> &b) {
  for (std::size_t i = 0; i < N; ++i) {
    if (b[i] == 0) {
      b[i] = 1;
      break;
    }
    b[i] = 0;
  }
}

int num_digits(int n) {
  int digits = 0;

  do {
    n = n / 10;
    ++digits;
  } while (n != 0);

  return digits;
}
}
}
