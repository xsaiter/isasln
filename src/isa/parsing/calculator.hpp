#pragma once

#include <string>

namespace isa::parsing {
double calculate_postfix(const std::string &postfix);
double calculate_infix(const std::string &infix);
int calculate_prefix(const std::string &prefix);
} // namespace isa::parsing
