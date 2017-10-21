#include <cassert>
#include <vector>
#include "numeric.hh"

namespace tss {
namespace msh {

void t_04_a_perfect(int m, int n, std::vector<int> &res) {
  assert(m < n);
  for (int i = m; i <= n; ++i) {
    if (isa::is_perfect_num(i)) {
      res.push_back(i);
    }
  }
}
}
}
