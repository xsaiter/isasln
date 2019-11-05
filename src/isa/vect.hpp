#pragma once

#include <algorithm>

namespace isa {
template <typename T, T default_initial = 0, T default_capacity = (1 << 4)>
class Vect {
public:
  using value_type = T;
  using iterator = T *;
  using const_iterator = const T *;

  using reference = T &;
  using const_reference = const T &;

  using size_type = std::size_t;

  Vect(const T &initial = default_initial) : Vect(default_capacity, initial) {}

  Vect(size_type capacity, const T &initial = default_initial)
      : capacity_(capacity), len_(0), elems_(new T[capacity]) {
    std::fill(elems_, elems_ + capacity_, initial);
  }

  Vect(std::initializer_list<T> il) : Vect(il.size()) {
    for (const auto &x : il) {
      push_back(x);
    }
  }

  Vect(const Vect &that) {}

  Vect &operator=(const Vect &that) { return *this; }

  Vect(Vect &&that) {
    elems_ = that.elems_;
    len_ = that.len_;
    capacity_ = that.capacity_;
  }

  Vect &operator=(Vect &&that) {
    delete[] elems_;
    elems_ = that.elems_;
    len_ = that.len_;
    capacity_ = that.capacity_;
    return *this;
  }

  ~Vect() noexcept { delete[] elems_; }

  reference operator[](size_type i) { return elems_[i]; }
  const_reference &operator[](size_type i) const { return elems_[i]; }

  void push_back(const T &elem) {
    if (capacity_ == len_) {
      auto new_capacity = 2 * capacity_;
      T *new_elems = new_copy(elems_, capacity_, new_capacity);
      delete[] elems_;
      elems_ = new_elems;
    }
    elems_[len_++] = elem;
  }

  iterator begin() { return elems_; }
  iterator end() { return elems_ + len_; }

  const_iterator cbegin() const { return elems_; }
  const_iterator cend() const { return elems_ + len_; }

  size_type len() const noexcept { return len_; }
  size_type capacity() const noexcept { return capacity_; }

  T *data() noexcept { return elems_; }
  const T *data() const noexcept { return elems_; }

private:
  size_type capacity_;
  size_type len_;
  T *elems_;

  static T *new_copy(T *s, size_type current_size, size_type new_size) {
    T *result = new T[new_size];
    try {
      std::copy(s, s + current_size, result);
    } catch (...) {
      delete[] result;
      throw;
    }
    return result;
  }
};
} // namespace isa
