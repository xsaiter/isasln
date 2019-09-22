#include "catalan.hpp"

namespace isa::ar {
unsigned long Catalan::get_number(unsigned int n) const {
  if (contains_key(n)) {
    return nums_.find(n)->second;
  }

  unsigned long res = 0;

  for (unsigned int i = 0; i < n; ++i) {
    unsigned long ni = get_number(i);
    if (!contains_key(i)) {
      nums_.insert(std::make_pair(i, ni));
    }

    unsigned int x = n - 1 - i;
    unsigned long nx = get_number(x);

    if (!contains_key(x)) {
      nums_.insert(std::make_pair(i, nx));
    }

    res += ni * nx;
  }

  return res;
}

bool Catalan::contains_key(const unsigned int &key) const {
  return nums_.find(key) != nums_.end();
}
} // namespace isa::ar
