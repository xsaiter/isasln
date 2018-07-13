#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <array>

#define ISA_UNUSED(x) ((void)(x))

namespace isa {

template <typename T, int ROWS, int COLS>
using arr2_u = std::array<std::array<int, COLS>, ROWS>;

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

template <typename T> struct acc_trait_s;

template <> struct acc_trait_s<int> { using R = long; };

template <> struct acc_trait_s<float> { using R = double; };

struct add_policy_s {
  template <typename T, typename R> static void calc(R &res, const T &value) {
    res += value;
  }
};

struct mul_policy_s {
  template <typename T, typename R> static void calc(R &res, const T &value) {
    res *= value;
  }
};

template <typename T, typename Policy = add_policy_s,
          typename Trait = acc_trait_s<T>>
auto acc(T *beg, T *end, const typename Trait::R &initial) {
  auto res = initial;
  while (beg != end) {
    Policy::calc(res, *beg);
    ++beg;
  }
  return res;
}

template <typename From, typename To> class maybe_cast {
  struct t_1 {};
  struct t_2 {
    t_1 t[2];
  };
  static t_1 as_t(To);
  static t_2 as_t(...);
  static From type_from();

public:
  enum { yes = sizeof(as_t(type_from())) == sizeof(t_1) };
};
}
