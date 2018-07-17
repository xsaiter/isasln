#pragma once

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

#include "../common.hh"

namespace isa {
namespace lia {

template <typename T> struct vec_scalar_s {
  const T &v_;
  vec_scalar_s(const T &v) : v_(v) {}
  T operator[](std::size_t i) const {
    ISA_UNUSED(i);
    return v_;
  }
  std::size_t size() const { return 0; }
};

template <typename T> struct vec_traits_s { using ref_u = const T &; };

template <typename T> struct vec_traits_s<vec_scalar_s<T>> {
  using ref_u = vec_scalar_s<T>;
};

template <typename T, typename R = std::vector<T>> class vec_s {
public:
  vec_s(std::size_t n, const T &initial) : elems_(n, initial) {}
  vec_s(const R &elems) : elems_(elems) {}

  template <typename T2, typename R2>
  vec_s(const vec_s<T2, R2> &other)
      : elems_(other.size()) {
    copy_elems(other);
  }

  template <typename T2, typename R2>
  vec_s<T, R> operator=(const vec_s<T2, R2> &other) {
    copy_elems(other);
    return *this;
  }

  T &operator[](const std::size_t i) { return elems_[i]; }
  T operator[](const std::size_t i) const { return elems_[i]; }

  R &elems() { return elems_; }
  const R &elems() const { return elems_; }

  std::size_t size() const { return elems_.size(); }

private:
  R elems_;

  template <typename T2, typename R2>
  inline void copy_elems(const vec_s<T2, R2> &other) {
    const std::size_t n = other.size();
    for (std::size_t i = 0; i < n; ++i) {
      elems_[i] = other[i];
    }
  }
};

template <typename T, typename R1, typename R2> struct binop_s {
  const R1 &r1_;
  const R2 &r2_;

  binop_s(const R1 &r1, const R2 &r2) : r1_(r1), r2_(r2) {}

  virtual std::size_t size() const {
    return this->r1_.size() != 0 ? this->r1_.size() : this->r2_.size();
  }

  virtual T operator[](const std::size_t i) const = 0;

  virtual ~binop_s() = default;
};

template <typename T, typename R1, typename R2>
struct vec_add_s : binop_s<T, R1, R2> {
  vec_add_s(const R1 &r1, const R2 &r2) : binop_s<T, R1, R2>(r1, r2) {}

  T operator[](const std::size_t i) const override {
    return this->r1_[i] + this->r2_[i];
  }
};

template <typename T, typename R1, typename R2>
struct vec_mul_s : binop_s<T, R1, R2> {
  vec_mul_s(const R1 &r1, const R2 &r2) : binop_s<T, R1, R2>(r1, r2) {}

  T operator[](const std::size_t i) const override {
    return this->r1_[i] * this->r2_[i];
  }
};

template <typename T, typename R1, typename R2>
struct vec_sub_s : binop_s<T, R1, R2> {
  vec_sub_s(const R1 &r1, const R2 &r2) : binop_s<T, R1, R2>(r1, r2) {}

  T operator[](const std::size_t i) const override {
    return this->r1_[i] - this->r2_[i];
  }
};

template <typename T, typename R1, typename R2>
auto operator+(const vec_s<T, R1> &v1, const vec_s<T, R2> &v2) {
  return vec_s<T, vec_add_s<T, R1, R2>>(
      vec_add_s<T, R1, R2>(v1.elems(), v2.elems()));
}

template <typename T, typename R1, typename R2>
auto operator*(const vec_s<T, R1> &v1, const vec_s<T, R2> &v2) {
  return vec_s<T, vec_mul_s<T, R1, R2>>(
      vec_mul_s<T, R1, R2>(v1.elems(), v2.elems()));
}

template <typename T, typename R1, typename R2>
auto operator-(const vec_s<T, R1> &v1, const vec_s<T, R2> &v2) {
  return vec_s<T, vec_sub_s<T, R1, R2>>(
      vec_sub_s<T, R1, R2>(v1.elems(), v2.elems()));
}

template <typename T, typename R>
auto operator*(const T &s, const vec_s<T, R> &v) {
  return vec_s<T, vec_mul_s<T, vec_scalar_s<T>, R>>(
      vec_mul_s<T, vec_scalar_s<T>, R>(vec_scalar_s<T>(s), v.elems()));
}
}
}
