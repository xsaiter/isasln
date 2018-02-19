#pragma once

#include <algorithm>

namespace isa {

template <typename T> class vect_s {
public:
  using iter_u = T *;
  using const_iter_u = const T *;

  using iter_ref_u = T &;
  using const_iter_ref_u = const T &;

  vect_s(std::size_t capacity)
      : capacity_(capacity), len_(0), elems_(new T[capacity]) {}

  vect_s() : vect_s(DEFAULT_CAPACITY) {}

  static const int DEFAULT_CAPACITY = 16;

  iter_ref_u operator[](std::size_t i) { return elems_[i]; }

  const_iter_ref_u &operator[](std::size_t i) const { return elems[i]; }

  void push_back(const T &elem) {
    if (capacity_ == len_) {
      std::size_t new_capacity = 2 * capacity_;
      T *new_elems = new_copy(elems_, capacity_, new_capacity);
      delete[] elems_;
      elems_ = new_elems;
    }
    elems_[len_++] = elem;
  }

  iter_u begin() { return elems_; }

  const_iter_u begin() const { return elems_; }

  const_iter_u end() const { return elems_ + len; }

  iter_u end() { return elems_ + len_; }

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
}
