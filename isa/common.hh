#pragma once

#include <algorithm>
#include <array>
#include <functional>
#include <string>
#include <vector>

#define NOMINMAX
#define ISA_UNUSED(x) ((void)(x))

namespace isa {
template <typename T, int Rows, int Cols>
using Arr2_i = std::array<std::array<int, Cols>, Rows>;

template <typename T> T min_of(const T &a, const T &b) {
  return std::min(a, b);
}

template <typename T, typename... R>
T min_of(const T &a, const T &b, const R &... c) {
  return std::min(a, min_of(b, c...));
}

template <typename T> T max_of(const T &a, const T &b) {
  return std::max(a, b);
}

template <typename T, typename... R>
T max_of(const T &a, const T &b, const R &... c) {
  return std::max(a, max_of(b, c...));
}

template <typename T> bool all_eq(const T &a, const T &b) { return a == b; }

template <typename T, typename... R>
bool all_eq(const T &a, const T &b, const R &... c) {
  return a == b && all_eq(b, c...);
}

template <typename T> struct Acc_trait;
template <> struct Acc_trait<int> { using R = long; };
template <> struct Acc_trait<float> { using R = double; };

struct Add_policy {
  template <typename T, typename R> static void calc(R &res, const T &value) {
    res += value;
  }
};

struct Mul_policy {
  template <typename T, typename R> static void calc(R &res, const T &value) {
    res *= value;
  }
};

template <typename T, typename Policy = Add_policy,
          typename Trait = Acc_trait<T>>
auto acc(T *beg, T *end, const typename Trait::R &initial) {
  auto res = initial;
  while (beg != end) {
    Policy::calc(res, *beg);
    ++beg;
  }
  return res;
}

template <typename From, typename To> class Maybe_cast {
  struct A {};
  struct B {
    A t[2];
  };
  static A as_t(To);
  static B as_t(...);
  static From type_from();

public:
  enum { yes = sizeof(as_t(type_from())) == sizeof(A) };
};

template <typename FwdIter> void shift(FwdIter beg, FwdIter end, int pos = 1) {
  std::rotate(beg, beg + pos, end);
}
} // namespace isa
