#pragma once

#include <sstream>
#include <stack>
#include <string>

namespace isa::parsing {
std::string postfix_to_infix(const std::string &postfix);
}
