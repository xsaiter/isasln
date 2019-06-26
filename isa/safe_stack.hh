#pragma once

#include <memory>
#include <stack>

namespace isa::safe {
template <typename T> class safe_stack_s {
public:
  void push(const T &elem) {}

private:
  std::stack<T> s_;
};
} // namespace isa::safe
