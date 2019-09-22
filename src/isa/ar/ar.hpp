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

template <typename F, typename T = std::size_t> struct Nums {
  struct Iterator;

  Nums(const T &from_, const T &to_) : from(from_), to(to_) {}

  Iterator begin() { return Iterator(from, to, f); }
  Iterator end() { return Iterator(to, to, f); }

  struct Iterator {
    Iterator(const T &n, const T &limit, const F &f)
        : n_(n), limit_(limit), f_(f) {}
    T operator*() { return n_; }
    Iterator &operator++() {
      ++n_;
      while (!f_(n_)) {
        ++n_;
        if (n_ >= limit_) {
          n_ = limit_;
          break;
        }
      }
      return *this;
    }
    bool operator==(const Iterator &o) { return n_ == o.n_; }
    bool operator!=(const Iterator &o) { return !operator==(o); }

  private:
    T n_, limit_;
    F f_;
  };

private:
  T from, to;
  F f;
};

namespace details {
template <typename T> struct Is_prime_num_policy {
  bool operator()(T x) const { return is_prime(x); }
};

struct Is_perfect_num_policy {
  bool operator()(std::size_t x) const { return is_perfect_num(x); }
};
} // namespace details

template <typename T>
using Is_prime_num = Nums<details::Is_prime_num_policy<T>, T>;
using Is_perfect_num = Nums<details::Is_perfect_num_policy, std::size_t>;
} // namespace isa::ar
