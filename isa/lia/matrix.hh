#pragma once

#include <vector>

namespace isa {
namespace lia {
template <typename T = int> class matrix_s {
public:
  matrix_s(int n, int m, const T &initial = 0) : n_(n), m_(m) {
    v_.resize(n, std::vector<T>(m, initial));
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

private:
  int n_, m_;
  std::vector<std::vector<T>> v_;
};
}
}
