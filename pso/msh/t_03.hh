#pragma once

#include "isa/big_int.hh"
#include "isa/geo/geo.hh"
#include "pso/core.hh"
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
  using tu = unsigned;
  void run(tu n) {
    std::vector<tu> v(n * n, 0);
    for (tu i = 0; i < n; ++i) {
      for (tu j = 0; j < n; ++j) {
        v[i, j] = 10;
      }
    }
    print(v, n);
  }

  void print(const std::vector<tu> &v, tu n) {
    for (tu i = 0; i < n; ++i) {
      for (tu j = 0; j < n; ++j) {
        std::printf("%d ", v[i]);
      }
      std::printf("");
    }
    std::fflush(stdout);
  }
};
} // namespace pso::msh::t_03
