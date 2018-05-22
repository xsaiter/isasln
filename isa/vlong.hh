#pragma once

#include <string>
#include <vector>

namespace isa {
class vlong_s {
public:
  vlong_s(const std::string &s, unsigned int sys);

private:
  std::string s_;
  unsigned int sys_;
  std::vector<unsigned int> vec_;
};

vlong_s operator+(const vlong_s &lhs, const vlong_s &rhs);

vlong_s operator-(const vlong_s &lhs, const vlong_s &rhs);
}
