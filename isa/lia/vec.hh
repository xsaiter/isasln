#pragma once

#include <vector>

namespace isa {
namespace lia {

template <typename T, typename E> class vec_expr_s {
  T operator[](std::size_t i) const { return static_cast<const E &>(*this)[i]; }
  std::size_t size() const { return static_cast<const E &>(*this).size(); }
  operator E &() { return static_cast<E &>(*this); }
  operator const E &() const { return static_cast<const E &>(*this); }
};

template <typename T> class vec_s : public vec_expr_s<T, vec_s<T>> {
public:
  explicit vec_s(std::size_t n) : elts_(n) {}
  T &operator[](std::size_t i) { return elts_[i]; }
  T operator[](std::size_t i) const { return elts_[i]; }
  std::size_t size() const { return elts_.size(); }

private:
  std::vector<T> elts_;
};

template <typename T, typename E1, typename E2>
class vec_sum_s : public vec_expr_s<T, vec_sum_s<T, E1, E2>> {
public:
  vec_sum_s(const E1 &e1, const E2 &e2) : e1_(e1), e2_(e2) {}

  T operator[](std::size_t i) const { return e1_[i] + e2_[i]; }
  std::size_t size() const { return e1_.size(); }

private:
  const E1 &e1_;
  const E2 &e2_;
};

template <typename T, typename E1, typename E2>
vec_sum_s<T, E1, E2> const operator+(E1 const &lhs, E2 const &rhs) {
  return vec_sum_s<T, E1, E2>(lhs, rhs);
}
}
}
