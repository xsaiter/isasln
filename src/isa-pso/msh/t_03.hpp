#pragma once

#include "../core.hpp"
#include "isa/big_int.hpp"
#include "isa/geo/geo.hpp"
#include <algorithm>
#include <cassert>
#include <cstdio>

namespace pso::msh::t_03 {
struct A_pfactor {
  std::string run(int n) {
    std::string res;
    return res;
  }
};

struct B_permut {
  std::vector<std::string> run(std::string &s) {
    std::vector<std::string> res{s};
    while (std::next_permutation(std::begin(s), std::end(s))) {
      res.push_back(s);
    }
    return res;
  }
};

struct C_piggy {
  using pw_u = std::pair<int, int>;
  using pws_u = std::vector<pw_u>;
  std::string run(int e, int f, const pws_u &pw) {
    assert(e <= f);
    std::string res;
    int m = f - e;
    return res;
  }
};

struct D_postcard_and_envelope {
  bool run(int pw, int ph, int ew, int eh) { return false; }
};

struct E_longprod {
  std::string run(const std::string &m, std::string &n) {
    constexpr int sys = 100;
    auto bim = isa::Big_int<sys>::from(m);
    auto bin = isa::Big_int<sys>::from(n);
    auto bres = bin * bim;
    auto res = bres.to();
    return res;
  }
};

struct F_serpent {
  using T = unsigned;

  void run(T n) {
    const T m = n * n;
    std::vector<T> v(m, 0);
    for (T i = 0; i < n; ++i) {
      for (T j = 0; j < n - i; ++j) {
        T k = i + j + 1;
        T s = k * (k + 1) / 2;
        if (k % 2 != 0) {
          s -= k - 1 - j;
        } else {
          s -= j;
        }
        v[i * n + j] = s;
      }
    }
    for (T i = 0; i < n; ++i) {
      for (T j = n - i; j < n; ++j) {
        T p = v[(n - 1 - i) * n + (n - 1 - j)];
        v[i * n + j] = m - p + 1;
      }
    }
    print(v, m, n);
  }

private:
  void print(const std::vector<T> &v, T m, T n) {
    for (T i = 0; i < m; ++i) {
      if (i % n == 0 && i > 0) {
        std::printf("\n");
      }
      std::printf("%5d ", v[i]);
    }
    std::fflush(stdout);
  }
};
} // namespace pso::msh::t_03
