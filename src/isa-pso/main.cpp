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

int get_val() { return 10; }

int main(int argc, char const *argv[]) {
  pso::eul::p_001_050::P_015 p15;
  p15.run<4>();
  return 0;
}
