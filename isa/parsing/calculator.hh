#pragma once

#include <string>

namespace isa {
namespace parsing {

double calculate_postfix(const std::string &postfix);
double calculate_infix(const std::string &infix);
}
}
