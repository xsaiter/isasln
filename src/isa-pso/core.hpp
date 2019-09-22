#pragma once

#include <memory>

namespace pso {
struct Single_linked_list_node {
  int data;
  std::shared_ptr<Single_linked_list_node> next = nullptr;
};

using Sln = Single_linked_list_node;
using Slnp = std::shared_ptr<Single_linked_list_node>;

Slnp make_sln(int data, Slnp next) {
  Slnp result(new Sln{data, next});
  return result;
}

bool is_leap_year(int year) {
  return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}
} // namespace pso
