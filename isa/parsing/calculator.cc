#include <stack>

#include <algorithm>
#include <iterator>
#include <math.h>
#include <sstream>

#include "../str/str_utils.hh"
#include "calculator.hh"
#include "infix_to_postfix.hh"

namespace isa::parsing {
static std::vector<std::string> get_tokens(const std::string &postfix) {
  return isa::str::str_split(postfix, ' ');
}

static bool is_op(const std::string &c) {
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

int calculate_prefix(const std::string &prefix) {
  std::stack<std::string> ss;

  for (char c : prefix) {
    if (c == '(' || c == ' ') {
    } else if (c == '+' || c == '-' || c == '*') {
      ss.push(std::string(1, c));
    } else if (c == ')') {
      std::stack<std::string> rev;
      while (!ss.empty()) {
        std::string t = ss.top();
        ss.pop();
        if (t == "+" || t == "-" || t == "*") {
          auto q = rev.top();
          rev.pop();
          int r = std::atoi(q.c_str());
          while (!rev.empty()) {
            q = rev.top();
            rev.pop();
            int num = std::atoi(q.c_str());
            if (t == "+") {
              r += num;
            } else if (t == "-") {
              r -= num;
            } else if (t == "*") {
              r *= num;
            }
          }
          ss.push(std::to_string(r));
          break;
        } else {
          rev.push(t);
        }
      }
    } else {
      ss.push(std::string(1, c));
    }
  }
  auto top = ss.top();
  return std::atoi(top.c_str());
}
} // namespace isa::parsing
