#include <queue>
#include <vector>

#include "postfix_to_infix.hh"

namespace isa::parsing {
static bool is_op(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

struct token_s {
  std::string value;
  bool is_op;
  bool is_num;
};

class expr_s {
public:
  std::string s;
  bool is_op = false;

  void process() {
    if (need_process()) {
      s = "(" + s + ")";
      processed = true;
    }
  }

  std::vector<expr_s> exprs;

private:
  bool processed = false;

  bool need_process() {
    if (processed || is_op) {
      return false;
    }

    for (const expr_s &x : exprs) {
      if (x.is_op) {
        if (x.s == "+" || x.s == "-") {
          return true;
        }
      }
    }

    return false;
  }
};

static std::string reverse_stack_to_string(std::stack<expr_s> &stack) {
  std::stack<expr_s> rev;
  while (!stack.empty()) {
    rev.push(stack.top());
    stack.pop();
  }

  std::ostringstream ss;
  while (!rev.empty()) {
    ss << rev.top().s;
    rev.pop();
  }

  return ss.str();
}

static void flush_buffer(std::string &buffer, std::stack<expr_s> &stack) {
  if (!buffer.empty()) {
    expr_s expr;
    expr.s = buffer;
    stack.push(expr);
    buffer.clear();
  }
}

std::string postfix_to_infix(const std::string &postfix) {
  std::stack<expr_s> stack;
  std::string buffer;

  for (const char &c : postfix) {
    if (is_op(c)) {
      flush_buffer(buffer, stack);

      expr_s b = stack.top();
      stack.pop();
      expr_s a = stack.top();
      stack.pop();

      if (c == '*' || c == '/') {
        b.process();
        a.process();
      }

      expr_s e;
      e.s = a.s + c + b.s;
      e.exprs.push_back(a);

      expr_s x;
      x.s = std::string(1, c);
      x.is_op = true;

      e.exprs.push_back(x);
      e.exprs.push_back(b);

      stack.push(e);
    } else {
      if (isspace(c)) {
        flush_buffer(buffer, stack);
      } else {
        buffer.push_back(c);
      }
    }
  }

  return reverse_stack_to_string(stack);
}
}
