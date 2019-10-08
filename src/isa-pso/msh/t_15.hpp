#pragma once

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

namespace pso::msh::t_15 {
struct F_polymul {
  struct Term {
    bool add;
    int factor;
    int degree;
  };

  using Terms = std::vector<Term>;

  std::string run(const std::string &x, const std::string &y) {
    auto tx = split_to_terms(x);
    auto ty = split_to_terms(y);
    auto tr = mul(tx, ty);
    auto res = write_to_str(reduce(tr));
    return res;
  }

  std::string write_to_str(const Terms &ts) {
    std::string r;
    return r;
  }

  Terms reduce(Terms &ts) {
    Terms r;
    std::sort(std::begin(ts), std::end(ts),
              [](const Term &x, const Term &y) { return x.degree > y.degree; });

    return r;
  }

  std::vector<Term> mul(const Terms &x, const Terms &y) {
    std::vector<Term> r;
    const auto nx = x.size();
    const auto ny = y.size();
    for (std::size_t i = 0; i < nx; ++i) {
      for (std::size_t j = 0; j < ny; ++j) {
        auto t = mul(x[i], y[j]);
        r.push_back(t);
      }
    }
    return r;
  }

  Term mul(const Term &x, const Term &y) {
    Term r;
    r.add = x.add && y.add;
    r.factor = x.factor * y.factor;
    r.degree = x.degree + y.degree;
    return r;
  }

  Terms split_to_terms(const std::string &s) {
    Terms res;
    return res;
  }
};
} // namespace pso::msh::t_15
