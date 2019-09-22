#pragma once

#include <string>

namespace isa::parsing {
bool check_balanced_brackets(const std::string &s);

/*
 * s->
 * s->(s)s
 */
class Balanced_brackets_parser {
public:
  explicit Balanced_brackets_parser(const std::string &s) : s_(s), i_(0) {}

  bool parse() { return parse_s() && i_ == s_.length(); }

private:
  std::string s_;
  std::size_t i_;

  bool parse_c(char c) {
    if (s_[i_] == c) {
      ++i_;
      return true;
    }
    return false;
  }

  bool parse_s() {
    std::size_t j = i_;
    bool ok = parse_c('(') && parse_s() && parse_c(')') && parse_s();
    if (!ok) {
      i_ = j;
    }
    return true;
  }
};
} // namespace isa::parsing
