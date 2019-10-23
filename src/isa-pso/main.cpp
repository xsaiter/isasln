#include "core.hpp"
#include "isa/sort.hpp"
#include "lia/matrix.hpp"
#include "rb_tree.hpp"
#include <string>
#include <thread>

#include "msh/t_08.hpp"
#include "msh/t_15.hpp"
#include "shen/shen_01.hpp"
#include "utils.hpp"

#include "eul/p_001_050.hpp"
#include "graph.hpp"

int main(int argc, char const *argv[]) {
  static const int x[] = {1, 2, 3, 4, 5, 6};
  auto ss = x[10];
  pso::eul::p_001_050::P_015 p15;
  std::vector<int> v;
  p15.run<4>();
  return 0;
}
