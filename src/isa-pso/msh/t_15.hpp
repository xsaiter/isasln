#pragma once

#include <algorithm>
#include <cassert>
#include <sstream>
#include <string>
#include <vector>

namespace pso::msh::t_15 {
struct F_polymul {
  struct Term {
    int factor;
    int degree;
  };

  using Terms = std::vector<Term>;
  using Size = std::size_t;

  std::string run(const std::string &x, const std::string &y) {
    auto tx = parse_terms(x);
    auto ty = parse_terms(y);
    auto tr = mul(tx, ty);
    auto res = write_to_str(reduce(tr));
    return res;
  }

  std::string write_to_str(const Terms &ts) {
    std::ostringstream ss;
    for (const Term &t : ts) {
      ss << t.factor;
      if (t.degree > 0) {
        ss << "x";
        if (t.degree > 1) {
          ss << "^" << t.degree;
        }
      }
    }
    return ss.str();
  }

  Terms reduce(Terms &ts) {
    Terms res;
    std::sort(std::begin(ts), std::end(ts),
              [](const Term &x, const Term &y) { return x.degree > y.degree; });
    const Size n = ts.size();
    Size i = 1;
    Term ta = ts[0];
    while (i < n) {
      if (ta.degree == ts[i].degree) {
        ta = add(ta, ts[i]);
      } else {
        res.push_back(ta);
        ta = ts[i];
      }
      ++i;
    }
    res.push_back(ta);
    return res;
  }

  std::vector<Term> mul(const Terms &x, const Terms &y) {
    std::vector<Term> r;
    const Size nx = x.size();
    const Size ny = y.size();
    for (Size i = 0; i < nx; ++i) {
      for (Size j = 0; j < ny; ++j) {
        r.push_back(mul(x[i], y[j]));
      }
    }
    return r;
  }

  Term mul(const Term &x, const Term &y) {
    Term res;
    res.factor = x.factor * y.factor;
    res.degree = x.degree + y.degree;
    return res;
  }

  Term add(const Term &x, const Term &y) {
    assert(x.degree == y.degree);
    Term res;
    res.factor = x.factor + y.factor;
    res.degree = x.degree;
    return res;
  }

  Terms parse_terms(const std::string &s) {
    Terms res;
    const Size n = s.size();
    Size i = 0;
    int state = 1;
    bool add = true;
    Term t;
    bool tc = false;
    while (i < n) {
      char c = s[i];
      switch (state) {
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      }
      t.factor = 1;
      t.degree = 0;
      if (c == '+') {
        add = true;
        state = 1;
      }
      if (c == '-') {
        add = false;
        state = 1;
      }
      if (c == 'x') {
        state = 3;
      }
      if (std::isdigit(c)) {
        if (state == 3) {
          state = 4;
        }
        state = true;
        ++i;
        std::ostringstream oss;
        oss << c;
        while (i < n && std::isdigit(s[i])) {
          oss << s[i];
          ++i;
        }
        auto num = std::atoi(oss.str().c_str());
        if (!add) {
          num *= (-1);
        }
        if (state == 4) {
          t.factor = num;
        } else {
          t.degree = num;
        }
      }
      ++i;
    }
    if (tc) {
      res.push_back(t);
    }
    return res;
  }
};
} // namespace pso::msh::t_15
