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

#include "isa/vect.hpp"

#include "eul/p_001_050.hpp"
#include "graph.hpp"

int main(int argc, char const *argv[]) {
  isa::Vect<int> vv{10, 20, 30};
  auto vvc = vv;
  vv[2] = 40;
  auto a = vv[2];
  auto b = vvc[2];
  return 0;
}
