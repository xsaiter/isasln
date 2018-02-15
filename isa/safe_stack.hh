#pragma once

#include <stack>
#include <memory>

namespace isa {
namespace safe {
template <typename T> class safe_stack_s {
public:
  void push(const T &elem) {}

private:
  std::stack<T> s_;
};
}
}
