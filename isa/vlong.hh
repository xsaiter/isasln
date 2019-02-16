#pragma once

#include <string>
#include <vector>

namespace isa {
template <unsigned int SYS> class vlong_s {
public:
  vlong_s(const std::string &s) {
    if (SYS == 10) {
    }
  }

  using type_u = unsigned int;

private:
  std::string s_;
  std::vector<type_u> vec_;
};
}
