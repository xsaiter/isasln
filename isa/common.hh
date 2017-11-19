#pragma once

#include <vector>
#include <string>

namespace isa {

template <class T> using arr2_u = std::vector<std::vector<T>>;

int fnv_hash(const std::string &s);
}
