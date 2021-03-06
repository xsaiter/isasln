#pragma once

#include <algorithm>
#include <array>
#include <functional>
#include <string>
#include <vector>

#define NOMINMAX
#define ISA_UNUSED(x) ((void)(x))
constexpr auto ISA_PI = 3.14;

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
  static A x(To);
  static B x(...);
  static From type_from();

public:
  enum { yes = sizeof(x(type_from())) == sizeof(A) };
};

template <typename FwdIt> void shift(FwdIt beg_it, FwdIt end_it, int pos = 1) {
  std::rotate(beg_it, beg_it + pos, end_it);
}

template <typename It = std::string::iterator>
std::string convert_to_str(It beg_it, It end_it) {
  return std::string(beg_it, end_it);
}

template <typename It, typename OutIt, typename Separator, typename Convert>
void split(It beg_it, It end_it, OutIt out_it, const Separator &separator,
           Convert convert) {
  auto it = beg_it;
  while (it != end_it) {
    auto sep_it = std::find(it, end_it, separator);
    *out_it = convert(it, sep_it);
    ++out_it;
    if (sep_it == end_it) {
      it = end_it;
    } else {
      it = std::next(sep_it);
    }
  }
}
} // namespace isa
