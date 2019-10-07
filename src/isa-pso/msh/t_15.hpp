#pragma once

#include <sstream>
#include <string>
#include <vector>

namespace pso::msh::t_15 {
struct F_polymul {
  struct Term {
    int factor;
    int d;
  };

  using Terms = std::vector<Term>;

  std::string run(const std::string &x, const std::string &y) {
    std::string res;
    const int nx = x.size();
    const int ny = y.size();
    return res;
  }

  std::vector<Term> mul(const std::vector<Term> &ts1,
                        const std::vector<Term> &ts2) {
    std::vector<Term> res;
    return res;
  }

  Term mul(const Term &t1, const Term &t2) {
    Term res;

    return res;
  }

  std::vector<Term> split_to_terms(const std::string &s) {
    std::vector<Term> res;
    const int n = s.size();
    int i = 0;
    while (i < n) {
      Term t;
      char c = s[i];
      if (std::isdigit(c)) {
        std::ostringstream fa;
        fa << c;
        while (i < n) {
          if (std::isdigit(s[i])) {
            fa << s[i];
            ++i;
          } else {
            --i;
            break;
          }
        }
      } else if (c == 'x') {

      } else {
        throw "unexpected char";
      }
      ++i;
    }
    return res;
  }
};
} // namespace pso::msh::t_15
