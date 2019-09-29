#include "core.hpp"
#include "isa/sort.hpp"
#include "lia/matrix.hpp"

int main(int argc, char const *argv[]) {
  std::vector<int> v{100, 5, 3, 13, 23};
  std::string s;
  isa::lia::Matrix<int> m(5, 5);
  auto elems = m * m;
  isa::sorting::bubble_sort(v.begin(), v.end());
  return 0;
}
