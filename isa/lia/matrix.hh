#pragma once

#include <vector>

namespace isa {
namespace lia {
template <typename T = int> class matrix_s {
public:
  matrix_s(int n, int m, const T &initial = 0) : n_(n), m_(m) {
    arr_.resize(n, std::vector<T>(m, initial));
  }

  template <int N, int M> static matrix_s<T> create(const T array[N][M]) {
    matrix_s<T> res(N, M);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        res.arr_[i][j] = array[i][j];
      }
    }
    return res;
  }

  explicit matrix_s(std::size_t n, const T &initial = 0)
      : matrix_s(n, n, initial) {}

  matrix_s(const matrix_s<T> &other)
      : n_(other.n_), m_(other.m_), arr_(other.arr_) {}

  inline T &operator()(int i, int j) { return arr_[i][j]; }
  inline const T &operator()(int i, int j) const { return arr_[i][j]; }

  matrix_s<T> &operator+=(const T &value);
  matrix_s<T> &operator*=(const T &value);

  template <typename U>
  friend matrix_s<U> operator*(const matrix_s<U> &a, const matrix_s<U> &b);

  template <typename U>
  friend matrix_s<U> operator+(const matrix_s<U> &a, const U &value);

  template <typename U>
  friend bool operator==(const matrix_s<U> &a, const matrix_s<U> &b);

private:
  int n_, m_;
  std::vector<std::vector<T>> arr_;
};

template <typename T> matrix_s<T> &matrix_s<T>::operator+=(const T &value) {
  for (int i = 0; i < n_; ++i) {
    for (int j = 0; j < m_; ++j) {
      arr_[i][j] += value;
    }
  }
  return *this;
}

template <typename T> matrix_s<T> &matrix_s<T>::operator*=(const T &value) {
  for (int i = 0; i < n_; ++i) {
    for (int j = 0; j < m_; ++j) {
      arr_[i][j] *= value;
    }
  }
  return *this;
}

template <typename U>
matrix_s<U> operator+(const matrix_s<U> &a, const U &value) {
  matrix_s<U> res(a);
  res += value;
  return res;
}

template <typename U>
matrix_s<U> operator*(const matrix_s<U> &a, const matrix_s<U> &b) {
  int n = a.n_;
  int m = b.m_;

  matrix_s<U> res(n, m);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < a.m_; ++k) {
        res.arr_[i][j] += a.arr_[i][k] * b.arr_[k][j];
      }
    }
  }

  return res;
}

template <typename U>
bool operator==(const matrix_s<U> &a, const matrix_s<U> &b) {
  int na = a.n_;
  int ma = a.m_;

  int nb = b.n_;
  int mb = b.m_;

  if (na != nb || ma != mb) {
    return false;
  }

  for (int i = 0; i < na; ++i) {
    for (int j = 0; j < ma; ++j) {
      if (a.arr_[i][j] != b.arr_[i][j]) {
        return false;
      }
    }
  }

  return true;
}
}
}
