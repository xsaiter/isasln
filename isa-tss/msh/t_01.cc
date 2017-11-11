#include <vector>
#include <sstream>
#include <string>
#include <cassert>

#include "numeric.hh"

#include "t_01.hh"

namespace tss {
namespace msh {

void t_01_a_primes(int m, int n, std::vector<int> &res) {
  assert(m <= n);

  for (int i = m; i <= n; ++i) {
    if (isa::is_prime(i)) {
      res.push_back(i);
    }
  }
}

static int calc(const std::vector<int> &a, int v) {
  int r = a[0];

  const int n = a.size();

  for (int i = 1; i < n; ++i) {
    if ((v & (1 << (i - 1))) > 0) {
      r += a[i];
    } else {
      r += a[i] * (-1);
    }
  }

  return r;
}

void t_01_b_expr(const std::vector<int> &a, int s, std::string &res) {
  const int n = a.size();
  const int nn = (n - 1) * (n - 1);

  int i = 0;

  while (i < nn && s != calc(a, i)) {
    i++;
  }

  std::ostringstream ss;

  if (i < nn) {
    ss << a[0];

    for (int j = 1; j < n; ++j) {
      if ((i & (1 << (j - 1))) > 0) {
        ss << '+';
      } else {
        ss << '-';
      }
      ss << a[j];
    }
  }

  res.assign(ss.str());
}

void t_01_c_incseq(const std::vector<int> &a, std::vector<int> &res) {}

bool t_01_d_tria_pt(const isa::geo::point_s &a, const isa::geo::point_s &b,
                    const isa::geo::point_s &c, const isa::geo::point_s &p) {
  int x1 = isa::geo::cross_product(a, b, p);
  int x2 = isa::geo::cross_product(b, c, p);
  int x3 = isa::geo::cross_product(c, a, p);

  return (x1 > 0 && x2 > 0 && x3 > 0) || (x1 < 0 && x2 < 0 && x3 < 0);
}
}
}
