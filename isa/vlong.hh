#pragma once

#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include "numeric.hh"

namespace isa {
template <std::size_t SYS> class vlong_s {
public:
  static vlong_s from(const std::string &s) {
    vlong_s res(s);
    std::size_t i = 0;
    auto d = res.d_;
    std::size_t n = s.size();
    while (i < n) {
      int pos = res.n_ - i - d;
      if (pos < 0) {
        d += pos;
        pos = 0;
      }
      auto num = std::stoi(s.substr(pos, d), nullptr, 10);
      res.vec_.push_back(num);
      i += d;
    }
    return res;
  }

  std::string to() const {
    std::ostringstream ss;
    auto i = vec_.rbegin();
    while (i != vec_.rend()) {
      auto nums = isa::num_digits(*i);
      if (nums == d_) {
        ss << *i;
      } else {
        for (auto k = 0; k < d_ - nums; ++k) {
          ss << '0';
        }
        ss << *i;
      }
      ++i;
    }
    return ss.str();
  }

  friend vlong_s operator+(const vlong_s &x, const vlong_s &y) {
    vlong_s res;
    return res;
  }

private:
  vlong_s() : d_(2) {}

  std::size_t n_;
  std::size_t d_;
  std::vector<int> vec_;
};
}
