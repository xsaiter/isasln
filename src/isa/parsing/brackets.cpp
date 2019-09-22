#include <algorithm>
#include <stack>

#include "brackets.hpp"

namespace isa {
namespace parsing {

bool check_balanced_brackets(const std::string &s) {
  std::stack<char> stack;

  for (const char &c : s) {
    if (c == '(' || c == '[' || c == '{') {
      stack.push(c);
    } else if (c == ')' || c == ']' || c == '}') {
      if (stack.empty()) {
        return false;
      }
      char p = stack.top();
      if ((c == ')' && p != '(') || (c == ']' && p != '[') ||
          (c == '}' && p != '{')) {
        return false;
      }
      stack.pop();
    }
  }

  return stack.empty();
}
} // namespace parsing
} // namespace isa
