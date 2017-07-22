#pragma once

#include <string>

namespace isa {
namespace parsing {

// shunting-yard algorithm
std::string infix_to_postfix(const std::string &infix);
}
}
