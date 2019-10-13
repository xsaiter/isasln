#include "core.hpp"
#include "isa/sort.hpp"
#include "lia/matrix.hpp"
#include "rb_tree.hpp"
#include <string>

#include "msh/t_08.hpp"
#include "msh/t_15.hpp"
#include "shen/shen_01.hpp"
#include "utils.hpp"

int main(int argc, char const *argv[]) {

  int n = 100;
  auto ttttt = n % 1000;
  int i = 1;
  int x = n;
  std::vector<int> nums;
  while (x > 0) {
    x = n % (10 * i);
    nums.push_back(x);
    x = n;
    ++i;
  }
  pso::msh::t_15::F_polymul f;
  using Term = pso::msh::t_15::F_polymul::Term;
  using Terms = pso::msh::t_15::F_polymul::Terms;
  Term t1;
  t1.factor = 10;
  t1.degree = 3;

  Term t2;
  t2.factor = 20;
  t2.degree = 3;

  Term t3;
  t3.factor = 5;
  t3.degree = 4;

  Term t4;
  t4.factor = 15;
  t4.degree = 4;

  Terms terms{t1, t2, t3, t4};

  auto r = f.parse_terms("10x^5+20x^4");
  return 0;
}
