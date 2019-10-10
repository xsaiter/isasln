#include "core.hpp"
#include "isa/sort.hpp"
#include "lia/matrix.hpp"
#include "rb_tree.hpp"
#include <string>

#include "msh/t_08.hpp"
#include "shen/shen_01.hpp"
#include "utils.hpp"

int main(int argc, char const *argv[]) {
  constexpr int n = 4;
  constexpr int m = 5;
  bool a[n][m];
  pso::shen::t_01::T_01_02_09 t;
  t.run<4, 5>(a);
  pso::msh::t_08::A_nosum x;
  std::vector<std::string> ss;
  std::vector<int> v{1, 2, 4, 8};
  auto res = x.run(v);
  return 0;
}
