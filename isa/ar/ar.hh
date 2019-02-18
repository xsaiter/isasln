#pragma once

#include <algorithm>
#include <bitset>
#include <iostream>
#include <memory>
#include <vector>

namespace isa::ar {
template <typename A, typename B> A fast_pow(A a, B b) {
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

template <typename T> bool is_prime(T n) {
  for (T i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

template <typename T> T gcd(T a, T b) {
  while (b != 0) {
    T c = a % b;
    a = b;
    b = c;
  }
  return (a > 0) ? a : -a;
}

template <typename T> bool is_relatively_prime(T a, T b) {
  return gcd(a, b) == 1;
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

std::vector<std::size_t> sieve_of_erat(std::size_t n);

std::size_t num_digits(std::size_t n);

std::size_t fact(std::size_t n);

bool is_perfect_num(std::size_t n);
}
