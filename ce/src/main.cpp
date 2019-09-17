#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

namespace aa::bb {
int foo_calc() { return 10; }
} // namespace aa::bb

int main() {
  auto res = aa::bb::foo_calc();
  std::vector<std::string> vv;
  vv.push_back("hello_1");
  vv.push_back("hello_2");
  printf("hello from makefile %d", 1011);
  return 0;
}
