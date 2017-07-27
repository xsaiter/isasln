#include <stack>

#include <math.h>
#include <algorithm>
#include <iterator>
#include <sstream>

#include "infix_to_postfix.hh"
#include "calculator.hh"
#include "strings/str_utils.hh"

namespace isa {
namespace parsing {

static std::vector<std::string> get_tokens(const std::string &postfix) {
  return isa::strings::str_split(postfix, ' ');
}

static bool is_op(std::string c) {
  return c == "+" || c == "-" || c == "*" || c == "/" || c == "^";
}

double calculate_postfix(const std::string &postfix) {
  std::stack<double> res;
  std::vector<std::string> tokens = get_tokens(postfix);

  for (const std::string &token : tokens) {
    if (is_op(token)) {
      double b = res.top();
      res.pop();
      double a = res.top();
      res.pop();

      if (token == "+") {
        res.push(a + b);
      } else if (token == "-") {
        res.push(a - b);
      } else if (token == "*") {
        res.push(a * b);
      } else if (token == "/") {
        res.push(a / b);
      } else if (token == "^") {
        res.push(pow(a, b));
      }
    } else {
      double num = atof(token.c_str());
      res.push(num);
    }
  }

  return res.top();
}

double calculate_infix(const std::string &infix) {
  std::string postfix = infix_to_postfix(infix);
  return calculate_postfix(postfix);
}
}
}
