#include <iostream>
#include <cstdio>

#include "common.hh"
#include "t_02.hh"
#include "geo/geo.hh"
#include "numeric.hh"

namespace msh {

std::vector<int> t_02_a_primes2(int m, int n) {
  std::vector<int> res;
  for (int i = m; i <= n; ++i) {
    if (isa::is_prime(i)) {
      res.push_back(i);
    }
  }
  return res;
}

void permut(const std::string &s, int pos, std::vector<std::string> &res) {
  const int n = static_cast<int>(s.size());
  int diff = n - pos;
  if (diff == 2) {
    res.push_back(s);
    // std::string ns(s.begin(), s.end() - diff)
    // res.push_back();
  }
}

std::vector<std::string> t_02_b_permut(const std::string &s) {
  const int n = static_cast<int>(s.size());
  auto len = isa::fact(n);
  std::vector<std::string> res(len);

  return res;
}

isa::lia::matrix_s<char> t_02_c_route(isa::lia::matrix_s<int> &nums) {
  isa::lia::matrix_s<char> res(nums.n(), nums.m());

  return res;
}

bool t_02_d_segments(const isa::geo::segment_s<int> &s1,
                     const isa::geo::segment_s<int> &s2) {
  return isa::geo::segments_intersect(s1, s2);
}

static int get_coil(int i, int j, int n) {
  return isa::min_of(n - i - 1, n - j - 1, i, j);
}

static int get_side_len(int coil, int n) { return n - 2 * coil; }

static int get_side_num(int i, int j, int side_len, int coil) {
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

static int get_num(int i, int j, int n) {
  int coil = get_coil(i, j, n);
  int side_len = get_side_len(coil, n);

  int len = 0;

  for (int k = 0; k < coil; ++k) {
    int s = get_side_len(k, n);
    len += (s - 1) * 4;
  }

  side_len -= 1;

  int r = 1 + len;

  int side_num = get_side_num(i, j, side_len, coil);

  r += (side_num - 1) * side_len;

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

void t_02_f_spiral(int n) {
  for (int i = 0; i < n; ++i) {

    std::printf("\n");

    for (int j = 0; j < n; ++j) {
      int num = get_num(i, j, n);

      std::printf("%5d", num);
    }
  }

  std::printf("\n");
}
}
