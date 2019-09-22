#pragma once

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#include "../common.hpp"

namespace isa::lia {
template <typename T> struct Vec_scalar {
  const T &v_;
  Vec_scalar(const T &v) : v_(v) {}
  T operator[](std::size_t i) const {
    ISA_UNUSED(i);
    return v_;
  }
  std::size_t size() const { return 0; }
};

template <typename T> struct Vec_traits { using Ref = const T &; };

template <typename T> struct Vec_traits<Vec_scalar<T>> {
  using Ref = Vec_scalar<T>;
};

template <typename T, typename R = std::vector<T>> class Vec {
public:
  Vec(std::size_t n, const T &initial) : elems_(n, initial) {}
  Vec(const R &elems) : elems_(elems) {}

  template <typename T2, typename R2>
  Vec(const Vec<T2, R2> &other) : elems_(other.size()) {
    copy_elems(other);
  }

  template <typename T2, typename R2>
  Vec<T, R> operator=(const Vec<T2, R2> &other) {
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
  inline void copy_elems(const Vec<T2, R2> &other) {
    const std::size_t n = other.size();
    for (std::size_t i = 0; i < n; ++i) {
      elems_[i] = other[i];
    }
  }
};

template <typename T, typename R1, typename R2> struct Binop {
  const R1 &r1_;
  const R2 &r2_;

  Binop(const R1 &r1, const R2 &r2) : r1_(r1), r2_(r2) {}
  virtual std::size_t size() const {
    return this->r1_.size() != 0 ? this->r1_.size() : this->r2_.size();
  }
  virtual T operator[](const std::size_t i) const = 0;
  virtual ~Binop() = default;
};

template <typename T, typename R1, typename R2>
struct Vec_add : Binop<T, R1, R2> {
  Vec_add(const R1 &r1, const R2 &r2) : Binop<T, R1, R2>(r1, r2) {}

  T operator[](const std::size_t i) const override {
    return this->r1_[i] + this->r2_[i];
  }
};

template <typename T, typename R1, typename R2>
struct Vec_mul : Binop<T, R1, R2> {
  Vec_mul(const R1 &r1, const R2 &r2) : Binop<T, R1, R2>(r1, r2) {}

  T operator[](const std::size_t i) const override {
    return this->r1_[i] * this->r2_[i];
  }
};

template <typename T, typename R1, typename R2>
struct Vec_sub : Binop<T, R1, R2> {
  Vec_sub(const R1 &r1, const R2 &r2) : Binop<T, R1, R2>(r1, r2) {}
  T operator[](const std::size_t i) const override {
    return this->r1_[i] - this->r2_[i];
  }
};

template <typename T, typename R1, typename R2>
auto operator+(const Vec<T, R1> &v1, const Vec<T, R2> &v2) {
  return Vec<T, Vec_add<T, R1, R2>>(Vec_add<T, R1, R2>(v1.elems(), v2.elems()));
}

template <typename T, typename R1, typename R2>
auto operator*(const Vec<T, R1> &v1, const Vec<T, R2> &v2) {
  return Vec<T, Vec_mul<T, R1, R2>>(Vec_mul<T, R1, R2>(v1.elems(), v2.elems()));
}

template <typename T, typename R1, typename R2>
auto operator-(const Vec<T, R1> &v1, const Vec<T, R2> &v2) {
  return Vec<T, Vec_sub<T, R1, R2>>(Vec_sub<T, R1, R2>(v1.elems(), v2.elems()));
}

template <typename T, typename R>
auto operator*(const T &s, const Vec<T, R> &v) {
  return Vec<T, Vec_mul<T, Vec_scalar<T>, R>>(
      Vec_mul<T, Vec_scalar<T>, R>(Vec_scalar<T>(s), v.elems()));
}
} // namespace isa::lia
