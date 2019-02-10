#pragma once

#include <memory>

namespace pso {
struct single_linked_list_node_s {
  int data;
  std::shared_ptr<single_linked_list_node_s> next;
};

using sln_u = single_linked_list_node_s;
using slnp_u = std::shared_ptr<single_linked_list_node_s>;

slnp_u make_sln(int data, slnp_u next) {
  slnp_u res(new sln_u{data, next});
  return res;
}

template <typename T> struct wh_s { T w, h; };
using whi_s = wh_s<int>;
}
