#pragma once

#include <string>
#include <sstream>
#include <stack>

namespace isa {
namespace parsing {
std::string postfix_to_infix(const std::string &postfix);
}
}
