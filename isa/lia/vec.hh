#pragma once

#include <vector>
#include <iostream>
#include <cassert>

namespace isa {
namespace lia {

template <typename T, typename Cont = std::vector<T>> class vec_s {
public:
  explicit vec_s(std::size_t n) : elems_(n) {}

  T &operator[](const std::size_t i) { return elems_[i]; }

  T operator[](const std::size_t i) const { return elems_[i]; }

  std::size_t size() const { return elems_.size(); }

private:
  Cont elems_;
};

template <typename T, typename Cont>
vec_s<T, Cont> operator+(const vec_s<T, Cont> &a, const vec_s<T, Cont> &b) {
  assert(a.size() == b.size());
  const std::size_t n = a.size();
  vec_s<T, Cont> res(n);
  for (std::size_t i = 0; i < n; ++i) {
    res[i] = a[i] + b[i];
  }
  return res;
}
}
}
