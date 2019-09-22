#include "core.hpp"
#include "isa/sort.hpp"
#include <string>

using sss = std::string;

int main(int argc, char const *argv[]) {
  std::vector<int> v{1, 5, 3, 13, 23};
  isa::sorting::bubble_sort(v.begin(), v.end());
  return 0;
}
