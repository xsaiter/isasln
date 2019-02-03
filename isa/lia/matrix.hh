#pragma once

#include <vector>

namespace isa {
namespace lia {
template <typename T = int, typename R = std::vector<std::vector<T>>>
class matrix_s {
public:
  matrix_s(int n, int m, const T &initial = 0) : n_(n), m_(m) {
    elems_.resize(n, std::vector<T>(m, initial));
  }

  template <int N, int M> static matrix_s<T> create(const T array[N][M]) {
    matrix_s<T> res(N, M);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        res.elems_[i][j] = array[i][j];
      }
    }
    return res;
  }

  static matrix_s<T> square(int n, const T &initial) {
    return matrix_s<T>(n, n, initial);
  }

  explicit matrix_s(std::size_t n, const T &initial = 0)
      : matrix_s(n, n, initial) {}

  matrix_s(const matrix_s<T> &other)
      : n_(other.n_), m_(other.m_), elems_(other.elems_) {}

  inline T &operator()(int i, int j) noexcept { return elems_[i][j]; }

  inline const T &operator()(int i, int j) const noexcept {
    return elems_[i][j];
  }

  int n() const noexcept { return n_; }
  int m() const noexcept { return m_; }

  matrix_s<T, R> &operator+=(const T &value);
  matrix_s<T, R> &operator*=(const T &value);

  template <typename U, typename X>
  friend matrix_s<U, X> operator*(const matrix_s<U, X> &a,
                                  const matrix_s<U, X> &b);

  template <typename U, typename X>
  friend matrix_s<U, X> operator+(const matrix_s<U, X> &a, const U &value);

  template <typename U, typename X>
  friend bool operator==(const matrix_s<U, X> &a, const matrix_s<U, X> &b);

private:
  int n_, m_;
  R elems_;
};

template <typename T, typename R>
matrix_s<T, R> &matrix_s<T, R>::operator+=(const T &value) {
  for (int i = 0; i < n_; ++i) {
    for (int j = 0; j < m_; ++j) {
      elems_[i][j] += value;
    }
  }
  return *this;
}

template <typename T, typename R>
matrix_s<T, R> &matrix_s<T, R>::operator*=(const T &value) {
  for (int i = 0; i < n_; ++i) {
    for (int j = 0; j < m_; ++j) {
      elems_[i][j] *= value;
    }
  }
  return *this;
}

template <typename U, typename X>
matrix_s<U, X> operator+(const matrix_s<U, X> &a, const U &value) {
  matrix_s<U, X> res(a);
  res += value;
  return res;
}

template <typename U, typename X>
matrix_s<U, X> operator*(const matrix_s<U, X> &a, const matrix_s<U, X> &b) {
  int n = a.n_;
  int m = b.m_;

  matrix_s<U, X> res(n, m);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < a.m_; ++k) {
        res.elems_[i][j] += a.elems_[i][k] * b.elems_[k][j];
      }
    }
  }

  return res;
}

template <typename U, typename X>
bool operator==(const matrix_s<U, X> &a, const matrix_s<U, X> &b) {
  int na = a.n_;
  int ma = a.m_;

  int nb = b.n_;
  int mb = b.m_;

  if (na != nb || ma != mb) {
    return false;
  }

  for (int i = 0; i < na; ++i) {
    for (int j = 0; j < ma; ++j) {
      if (a.elems_[i][j] != b.elems_[i][j]) {
        return false;
      }
    }
  }

  return true;
}
}
}
