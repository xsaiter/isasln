#include "core.hpp"
#include "isa/sort.hpp"
#include "lia/matrix.hpp"
#include "rb_tree.hpp"
#include <string>

#include "shen/shen_01.hpp"

#include "msh/t_08.hpp"

#include "utils.hpp"

int main(int argc, char const *argv[]) {
  pso::msh::t_08::A_nosum a;
  std::vector<int> v{1, 2, 4, 8};
  auto res = a.run(v);
  return 0;
}
