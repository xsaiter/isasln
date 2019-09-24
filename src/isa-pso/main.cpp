#include "core.hpp"
#include "isa/sort.hpp"
#include <string>

int main(int argc, char const *argv[]) {
  std::vector<int> result{1, 5, 3, 13, 23};
  isa::sorting::bubble_sort(result.begin(), result.end());
  return 0;
}
