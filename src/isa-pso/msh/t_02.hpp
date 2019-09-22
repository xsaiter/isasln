#pragma once

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "isa/ar/ar.hpp"
#include "isa/common.hpp"
#include "isa/geo/geo.hpp"
#include "isa/lia/matrix.hpp"
#include "isa/str/str_utils.hpp"

#include "t_02.hpp"

namespace pso::msh::t_02 {
struct A_primes2 {
  std::vector<int> run(int m, int n) {
    std::vector<int> res;
    for (int i = m; i <= n; ++i) {
      if (isa::ar::is_prime(i)) {
        res.push_back(i);
      }
    }
    return res;
  }
};

struct B_permut {
  std::vector<std::string> run(std::string &s) {
    std::vector<std::string> res;
    const int n = static_cast<int>(s.size());
    if (n > 0) {
      if (n == 1) {
        res.push_back(s);
      } else {
        rec(s, n, n, res);
      }
    }
    return res;
  }

private:
  void rec(std::string &s, int n, int m, std::vector<std::string> &res) {
    if (m == 2) {
      res.push_back(s);
      res.push_back(isa::str::str_mirror(s, n - m));
    } else {
      for (auto i = 0; i < m; ++i) {
        rec(s, n, m - 1, res);
        isa::shift(std::next(std::begin(s), n - m), std::end(s));
      }
    }
  }
};

struct C_route {
  isa::lia::Matrix<char> run(isa::lia::Matrix<int> &nums) {
    isa::lia::Matrix<char> res(nums.n(), nums.m());
    return res;
  }
};

struct D_segments {
  using Segment_i = isa::geo::Segment<int>;
  bool run(const Segment_i &s1, const Segment_i &s2) {
    return isa::geo::segments_intersect(s1, s2);
  }
};

struct E_longsum {
  std::string run(const std::string &n, std::string &m) {
    std::string res;
    return res;
  }
};

struct F_spiral {
  void run(int n) {
    for (int i = 0; i < n; ++i) {
      std::printf("\n");
      for (int j = 0; j < n; ++j) {
        int num = get_num(i, j, n);
        std::printf("%5d", num);
      }
    }
    std::printf("\n");
  }

private:
  int get_coil(int i, int j, int n) {
    return isa::min_of(n - i - 1, n - j - 1, i, j);
  }

  int get_side_len(int coil, int n) { return n - 2 * coil; }

  int get_side_num(int i, int j, int side_len, int coil) {
    int ii = i - coil;
    int jj = j - coil;
    if (ii == 0) {
      return 1;
    }
    if (ii == side_len) {
      return 3;
    }
    if (jj == 0) {
      return 4;
    }
    if (jj == side_len) {
      return 2;
    }
    throw std::logic_error("no side");
  }

  int get_num(int i, int j, int n) {
    int coil = get_coil(i, j, n);
    int side_len = get_side_len(coil, n);
    int len = 0;

    for (int k = 0; k < coil; ++k) {
      int s = get_side_len(k, n);
      len += (s - 1) * 4;
    }

    side_len -= 1;
    int side_num = get_side_num(i, j, side_len, coil);
    int r = 1 + len + (side_num - 1) * side_len;

    if (side_num == 1) {
      r += j - coil;
    } else if (side_num == 2) {
      r += i - coil;
    } else if (side_num == 3) {
      r += side_len - (j - coil);
    } else if (side_num == 4) {
      r += side_len - (i - coil);
    }

    return r;
  }
};
} // namespace pso::msh::t_02
