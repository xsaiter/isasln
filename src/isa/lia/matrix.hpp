#pragma once

#include <vector>

namespace isa::lia {
template <typename T = int, typename R = std::vector<std::vector<T>>>
class Matrix {
public:
  Matrix(std::size_t n, std::size_t m, const T &initial = 0) : n_(n), m_(m) {
    elems_.resize(n, std::vector<T>(m, initial));
  }

  template <int N, int M> static Matrix<T> create(const T array[N][M]) {
    Matrix<T> res(N, M);    
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        res.elems_[i][j] = array[i][j];
      }
    }
    return res;
  }

  static Matrix<T> square(std::size_t n, const T &initial) {
    return Matrix<T>(n, n, initial);
  }

  explicit Matrix(std::size_t n, const T &initial = 0)
      : Matrix(n, n, initial) {}

  Matrix(const Matrix<T> &other)
      : n_(other.n_), m_(other.m_), elems_(other.elems_) {}

  inline T &operator()(std::size_t i, std::size_t j) noexcept {
    return elems_[i][j];
  }

  inline const T &operator()(std::size_t i, std::size_t j) const noexcept {
    return elems_[i][j];
  }

  std::size_t n() const noexcept { return n_; }
  std::size_t m() const noexcept { return m_; }

  Matrix<T, R> &operator+=(const T &value);
  Matrix<T, R> &operator*=(const T &value);

  template <typename U, typename X>
  friend Matrix<U, X> operator*(const Matrix<U, X> &a, const Matrix<U, X> &b);

  template <typename U, typename X>
  friend Matrix<U, X> operator+(const Matrix<U, X> &a, const U &value);

  template <typename U, typename X>
  friend bool operator==(const Matrix<U, X> &a, const Matrix<U, X> &b);

private:
  std::size_t n_, m_;
  R elems_;
};

template <typename T, typename R>
Matrix<T, R> &Matrix<T, R>::operator+=(const T &value) {
  for (int i = 0; i < n_; ++i) {
    for (int j = 0; j < m_; ++j) {
      elems_[i][j] += value;
    }
  }
  return *this;
}

template <typename T, typename R>
Matrix<T, R> &Matrix<T, R>::operator*=(const T &value) {
  for (int i = 0; i < n_; ++i) {
    for (int j = 0; j < m_; ++j) {
      elems_[i][j] *= value;
    }
  }
  return *this;
}

template <typename U, typename X>
Matrix<U, X> operator+(const Matrix<U, X> &a, const U &value) {
  Matrix<U, X> res(a);
  res += value;
  return res;
}

template <typename U, typename X>
Matrix<U, X> operator*(const Matrix<U, X> &a, const Matrix<U, X> &b) {
  int n = a.n_;
  int m = b.m_;
  Matrix<U, X> res(n, m);
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
bool operator==(const Matrix<U, X> &a, const Matrix<U, X> &b) {
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
} // namespace isa::lia
