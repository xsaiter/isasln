#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <vector>

#include "infix_to_postfix.hpp"

namespace isa::parsing {
struct token_s {
  token_s(const std::string &s_, bool is_num_) : s(s_), is_num(is_num_) {}
  std::string s;
  bool is_num;
};

static void flush_buffer(std::string &buffer, std::vector<token_s> &tokens) {
  if (!buffer.empty()) {
    tokens.push_back(token_s(buffer, true));
    buffer.clear();
  }
}

static bool is_op(const char c) {
  return c == '*' || c == '/' || c == '+' || c == '-' || c == '(' || c == ')' ||
         c == '^';
}

static std::vector<token_s> get_tokens(const std::string &infix) {
  std::vector<token_s> tokens;
  std::string buffer;

  for (const char &c : infix) {
    if (isdigit(c)) {
      buffer += c;
    } else if (is_op(c)) {
      flush_buffer(buffer, tokens);
      tokens.push_back(token_s(std::string(1, c), false));
    }
  }

  flush_buffer(buffer, tokens);
  return tokens;
}

// shunting-yard algorithm
std::string infix_to_postfix(const std::string &infix) {
  std::queue<token_s> q;
  std::stack<token_s> s;

  std::vector<token_s> tokens = get_tokens(infix);

  for (token_s &token : tokens) {
    if (token.is_num) {
      q.push(token);
    } else {
      if (token.s == "(") {
        s.push(token);
      } else if (token.s == ")") {
        while (!s.empty()) {
          token_s t = s.top();
          if (t.s == "(") {
            s.pop();
            break;
          }
          q.push(t);
          s.pop();
        }
      } else if (token.s == "^") {
        while (!s.empty()) {
          token_s t = s.top();
          if (t.s == "(" || t.s == "^" || t.s == "*" || t.s == "/") {
            break;
          }
          q.push(t);
          s.pop();
        }
      } else if (token.s == "+" || token.s == "-") {
        while (!s.empty()) {
          token_s t = s.top();
          if (t.s == "(") {
            break;
          }
          q.push(t);
          s.pop();
        }
      } else {
        if (token.s == "*" || token.s == "/") {
          while (!s.empty()) {
            token_s t = s.top();
            if (t.s == "(") {
              break;
            }
            if (t.s == "*" || t.s == "/" || t.s == "^") {
              q.push(t);
              s.pop();
            } else {
              break;
            }
          }
        }
      }

      if (token.s != "(" && token.s != ")") {
        s.push(token);
      }
    }
  }

  while (!s.empty()) {
    q.push(s.top());
    s.pop();
  }

  std::ostringstream ss;
  while (!q.empty()) {
    ss << q.front().s + " ";
    q.pop();
  }

  return ss.str();
}
} // namespace isa::parsing
