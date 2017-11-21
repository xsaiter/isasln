#pragma once

#include <vector>
#include <string>
#include <algorithm>

namespace isa {

template <class T> using arr2_u = std::vector<std::vector<T>>;

template <class T> T min_of(const T &a, const T &b) { return std::min(a, b); }

template <class T, class... R>
T min_of(const T &a, const T &b, const R &... c) {
  return std::min(a, min_of(b, c...));
}

template <class T> T max_of(const T &a, const T &b) { return std::max(a, b); }

template <class T, class... R>
T max_of(const T &a, const T &b, const R &... c) {
  return std::max(a, max_of(b, c...));
}

int fnv_hash(const std::string &s);
}
