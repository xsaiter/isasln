#include "core.hpp"
#include "isa/sort.hpp"
#include "lia/matrix.hpp"
#include <string>
#include "rb_tree.hpp"

int main(int argc, char const *argv[]) {
  int n = 5;  

  std::vector<std::vector<int>> vv;
  vv.resize(10, std::vector<int>(5, 0));
  
  vv[8][4] = 10;

  std::vector<int> v{100, 5, 3, 13, 23};
  auto x = v.begin();  
  std::string s;  
  isa::lia::Matrix<int> m(5, 5);

  auto elems = m * m;

  isa::sorting::bubble_sort(v.begin(), v.end());
  return 0;
}
