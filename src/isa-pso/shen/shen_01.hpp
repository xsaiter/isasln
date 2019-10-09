#pragma once

#include <string>
#include <vector>

#include "../core.hpp"

namespace pso::shen::t_01 {
struct T_01_01_01 {
  void run() {
    auto a = 1;
    auto b = 2;
    auto t = a;
    a = b;
    b = t;
  }
};

struct T_01_01_02 {
  void run() {
    auto a = 1;
    auto b = 2;
    a += b;
    b = a - b;
    a -= b;
  }
};

struct T_01_01_03 {
  void run() {
    int a = 1;
    int b = 2;
    std::string s;
  }
};
} // namespace pso::shen::t_01
