#pragma once

#include <vector>

namespace isa {
namespace lia {

template <typename T, typename Container = std::vector<T>> class vec_s {
public:
  explicit vec_s(std::size_t n) : elems_(n) {}
  explicit vec_s(const Container &other) : elems_(other) {}

  T &operator[](std::size_t i) { return elems_[i]; }
  T operator[](std::size_t i) const { return elems_[i]; }
  std::size_t size() const { return elems_.size(); }
  Container &elems() { return elems_; }

private:
  Container elems_;
};

template <typename T, typename A, typename B> class vec_add_s {
public:
  vec_add_s(const A &a, const B &b) : a_(a), b_(b) {}

  T operator[](std::size_t i) const { return a_[i] + b_[i]; }
  std::size_t size() const { return a_.size(); }

private:
  const A &a_;
  const B &b_;
};

template <typename T, typename A, typename B>
vec_s<T, vec_add_s<T, A, B>> operator+(const vec_s<T, A> &a,
                                       const vec_s<T, B> &b) {
  return vec_s<T, vec_add_s<T, A, B>>(vec_add_s<T, A, B>(a.elems(), b.elems()));
}
}
}
