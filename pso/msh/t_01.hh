#pragma once

#include <algorithm>
#include <cassert>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "isa/geo/geo.hh"
#include "pso/core.hh"

#include "isa/ar/ar.hh"

namespace pso::msh::t_01 {
struct a_primes {
  void run(int m, int n, std::vector<int> &res) {
    assert(m <= n);
    for (int i = m; i <= n; ++i) {
      if (isa::ar::is_prime(i)) {
        res.push_back(i);
      }
    }
  }
};

struct b_expr {
  void run(const std::vector<int> &nums, int s, std::string &res) {
    const std::size_t n = nums.size();
    const std::size_t nn = (n - 1) * (n - 1);
    std::size_t i = 0;
    while (i < nn && s != calc(nums, i)) {
      i++;
    }
    std::ostringstream ss;
    if (i < nn) {
      ss << nums[0];
      for (std::size_t j = 1; j < n; ++j) {
        if ((i & (1 << (j - 1))) > 0) {
          ss << '+';
        } else {
          ss << '-';
        }
        ss << nums[j];
      }
    }
    res.assign(ss.str());
  }

private:
  int calc(const std::vector<int> &nums, std::size_t v) {
    int r = nums[0];
    const std::size_t n = nums.size();
    for (std::size_t i = 1; i < n; ++i) {
      if ((v & (1 << (i - 1))) > 0) {
        r += nums[i];
      } else {
        r += nums[i] * (-1);
      }
    }
    return r;
  }
};

struct c_incseq {
  std::vector<int> run(const std::vector<int> &a) {
    std::vector<int> res;
    return res;
  }
};

struct d_tria_pt {
  using pti = isa::geo::point_s<int>;
  bool run(const pti &a, const pti &b, const pti &c, const pti &p) {
    using namespace isa::geo;
    auto x1 = cross_product(a, b, p);
    auto x2 = cross_product(b, c, p);
    auto x3 = cross_product(c, a, p);
    return (x1 > 0 && x2 > 0 && x3 > 0) || (x1 < 0 && x2 < 0 && x3 < 0);
  }
};

struct e_power {
  std::string run(unsigned a, unsigned n) {
    using tt = unsigned;
    assert(1 <= a && a <= 9);
    assert(1 <= n && n <= 7000);
    std::vector<tt> v(n, 0);
    v[0] = 1;
    tt len = 1;
    for (tt i = 0; i < n; ++i) {
      tt q = 0;
      for (tt j = 0; j < len; ++j) {
        tt t = v[j] * a + q;
        tt rem = t % 10;
        v[j] = rem;
        q = (t - rem) / 10;
      }
      if (q > 0) {
        v[len] = q;
        len++;
      }
    }
    std::string s;
    s.reserve(len);
    std::transform(v.rbegin() + n - len, v.rend(), std::back_inserter(s),
                   [](tt x) { return std::to_string(x)[0]; });
    return s;
  }
};

struct f_poker {
  std::string run(int x1, int x2, int x3, int x4, int x5) {
    constexpr unsigned int n = 14;
    int a[n]{0};
    ++a[x1];
    ++a[x2];
    ++a[x3];
    ++a[x4];
    ++a[x5];
    int f23 = 0;
    int f2 = 0;
    int chain = 0;
    for (unsigned int i = 0; i < n; ++i) {
      if (a[i] == 5) {
        return "impossible";
      }
      if (a[i] == 4) {
        return "four of a kind";
      }
      if (a[i] == 2) {
        if (f23 == 3) {
          f23 = -1;
        } else {
          f23 = 2;
        }
        f2++;
      } else if (a[i] == 3) {
        if (f23 == 2) {
          f23 = -1;
        } else {
          f23 = 3;
        }
      }
      if (f23 == -1) {
        return "full house";
      }
      if (a[i] == 0) {
        chain = 0;
      } else {
        ++chain;
        if (chain == 5) {
          return "straight";
        }
      }
    }
    if (f23 == 3) {
      return "three of kind";
    }
    if (f2 == 1) {
      return "one pair";
    }
    if (f2 == 2) {
      return "two pairs";
    }
    return "nothing";
  }
};
} // namespace pso::msh::t_01
