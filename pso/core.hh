#pragma once

#include <memory>

namespace pso {
struct single_linked_list_node_s {
  int data;
  std::shared_ptr<single_linked_list_node_s> next = nullptr;
};

using sln_u = single_linked_list_node_s;
using slnp_u = std::shared_ptr<single_linked_list_node_s>;

slnp_u make_sln(int data, slnp_u next) {
  slnp_u res(new sln_u{data, next});
  return res;
}

bool is_leap_year(int year) {
  return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}
} // namespace pso
