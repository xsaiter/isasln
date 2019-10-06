#pragma once

#include <string>

namespace isa {
int fnv_hash(const std::string &s);

struct Constants {
  static constexpr double PI = 3.14;
};
} // namespace isa
