#pragma once

#include <memory>

namespace pso {
struct linked_list_node_s {
  int data;
  std::shared_ptr<linked_list_node_s> next;
};
}
