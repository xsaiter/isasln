#include "t_10.hh"

namespace tss {
namespace msh {

std::string fibs(int n) {
  std::string sss("a");
  if (n == 0) {
    return sss;
  }

  std::string ss("b");
  if (n == 1) {
    return ss;
  }

  std::string s;

  for (int i = 2; i <= n; ++i) {
    s = ss + sss;
    sss = ss;
    ss = s;
  }

  return s;
}

int repeats_bound(const std::string &s, std::size_t bound,
                  const std::string &p) {
  int res = 0;

  const std::size_t n = s.size();
  const std::size_t m = p.size();

  std::size_t beg = bound >= m ? bound - m : 0;

  for (std::size_t i = beg; i < bound; ++i) {
    int j = 0;
    while (j < m && s[i + j] == p[j]) {
      ++j;
    }
    if (j == m && i + j > bound) {
      ++res;
    }
  }

  return res;
}

int t_10_b_fibostr(int n, const std::string &s) {
  std::string a("a");
  int ra = a == s ? 1 : 0;
  if (n == 0) {
    return ra;
  }

  std::string b("b");
  int rb = b == s ? 1 : 0;
  if (n == 1) {
    return rb;
  }

  std::string x;
  int rx = 0;

  for (int i = 2; i <= n; ++i) {
    x = b + a;

    int e = repeats_bound(x, b.size(), s);

    a = b;
    b = x;

    rx = rb + ra + e;
    ra = rb;
    rb = rx;
  }

  return rx;
}
}
}
