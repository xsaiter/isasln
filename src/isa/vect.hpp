#pragma once

#include <algorithm>

namespace isa {
template <typename T> class Vect {
public:
  using Iter = T *;
  using Const_iter = const T *;

  using Iter_ref = T &;
  using Const_iter_ref = const T &;

  Vect(std::size_t capacity)
      : capacity_(capacity), len_(0), elems_(new T[capacity]) {}

  Vect() : Vect(DEFAULT_CAPACITY) {}

  static const int DEFAULT_CAPACITY = 16;

  Iter_ref operator[](std::size_t i) { return elems_[i]; }
  Const_iter_ref &operator[](std::size_t i) const { return elems_[i]; }

  void push_back(const T &elem) {
    if (capacity_ == len_) {
      auto new_capacity = 2 * capacity_;
      T *new_elems = new_copy(elems_, capacity_, new_capacity);
      delete[] elems_;
      elems_ = new_elems;
    }
    elems_[len_++] = elem;
  }

  Iter begin() { return elems_; }
  Iter end() { return elems_ + len_; }

  Const_iter begin() const { return elems_; }
  Const_iter end() const { return elems_ + len_; }

  std::size_t len() const noexcept { return len_; }
  std::size_t capacity() const noexcept { return capacity_; }

private:
  std::size_t capacity_;
  std::size_t len_;
  T *elems_;

  static T *new_copy(T *s, std::size_t ns, std::size_t nr) {
    T *r = new T[nr];
    try {
      std::copy(s, s + ns, r);
    } catch (...) {
      delete[] r;
      throw;
    }
    return r;
  }
};
} // namespace isa
