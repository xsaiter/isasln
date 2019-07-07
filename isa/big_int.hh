#pragma once

#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include "ar/ar.hh"

namespace isa {
template <std::size_t SYS> class BigInt {
public:
  static BigInt from(const std::string &s) {
    BigInt res;
    auto d = res.d_;
    std::size_t i = 0;
    const std::size_t n = s.size();
    while (i < n) {
      int pos = res.n_ - i - d;
      if (pos < 0) {
        d += pos;
        pos = 0;
      }
      auto num = std::stoi(s.substr(pos, d), nullptr, 10);
      res.v_.push_back(num);
      i += d;
    }
    return res;
  }

  std::string to() const {
    std::ostringstream ss;
    auto i = v_.rbegin();
    while (i != v_.rend()) {
      auto nums = isa::ar::num_digits(*i);
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

  friend BigInt operator+(const BigInt &x, const BigInt &y) {
    BigInt res;
    return res;
  }

  friend BigInt operator*(const BigInt &x, const BigInt &y) {
    BigInt res;
    return res;
  }

private:
  BigInt() : d_(2) {}

  std::size_t n_;
  std::size_t d_;
  std::vector<int> v_;
};

} // namespace isa
