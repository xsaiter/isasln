#include "core.hpp"
#include "isa/sort.hpp"
#include "lia/matrix.hpp"
#include "rb_tree.hpp"
#include <string>

#include "msh/t_08.hpp"
#include "shen/shen_01.hpp"
#include "utils.hpp"

int main(int argc, char const *argv[]) {
  int i = 2;
  int n = 10;
  while (i > -1) {
    if (i == n - 1) {
      break;
    }
    i = i + (n - i) / 2;
  }
  return 0;
}
