#pragma once

#include <vector>

namespace isa {
namespace lia {
template <typename T = int> class matrix_s {
public:
  matrix_s(int n, int m, const T &initial = 0) : n_(n), m_(m) {
    v_.resize(n, std::vector<T>(m, initial));
  }

  matrix_s(int n, int m, const T array[10][10], int temp) : matrix_s(n, m) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        v_[i][j] = array[i][j];
      }
    }
  }

  explicit matrix_s(std::size_t n, const T &initial = 0)
      : matrix_s(n, n, initial) {}

  matrix_s(const matrix_s<T> &other)
      : n_(other.n_), m_(other.m_), v_(other.v_) {}

  inline T &operator()(int i, int j) { return v_[i][j]; }

  friend matrix_s<T> operator*(const matrix_s<T> &a, const matrix_s<T> &b) {
    int n = a.n_;
    int m = b.m_;

    matrix_s<T> res(n, m);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < a.m_; ++k) {
          res.v_[i][j] += a.v_[i][k] * b.v_[k][j];
        }
      }
    }

    return res;
  }

  friend matrix_s<T> operator+(const matrix_s<T> &a, const T &value) {
    matrix_s<T> res(a);

    for (int i = 0; i < a.n_; ++i) {
      for (int j = 0; j < a.m_; ++j) {
        res.v_[i][j] += value;
      }
    }

    return res;
  }

  friend bool operator==(const matrix_s<T> &a, const matrix_s<T> &b) {
    int na = a.n_;
    int ma = a.m_;

    int nb = b.n_;
    int mb = b.m_;

    if (na != nb || ma != mb) {
      return false;
    }

    for (int i = 0; i < na; ++i) {
      for (int j = 0; j < ma; ++j) {
        if (a.v_[i][j] != b.v_[i][j]) {
          return false;
        }
      }
    }

    return true;
  }

private:
  int n_, m_;
  std::vector<std::vector<T>> v_;
};
}
}
