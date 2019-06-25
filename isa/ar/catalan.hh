#pragma once

#include <map>

namespace isa::ar {
class catalan_numbers_s {
public:
  unsigned long get_number(unsigned int n) const;

private:
  mutable std::map<unsigned int, unsigned long> nums_ = {{0, 1}};
  bool contains_key(const unsigned int &key) const;
};
} // namespace isa::ar
