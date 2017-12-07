#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <functional>

namespace isa {

#define print_set_pos(x, y) printf("\033[%d;%dH", (x), (y))

template <typename T> using arr2_u = std::vector<std::vector<T>>;

template <typename T> T min_of(const T &a, const T &b) {
  return std::min(a, b);
}

template <typename T, typename... R>
T min_of(const T &a, const T &b, const R &... c) {
  return std::min(a, min_of(b, c...));
}

template <typename T> T max_of(const T &a, const T &b) {
  return std::max(a, b);
}

template <typename T, typename... R>
T max_of(const T &a, const T &b, const R &... c) {
  return std::max(a, max_of(b, c...));
}

template <typename T> bool all_eq(const T &a, const T &b) { return a == b; }

template <typename T, typename... R>
bool all_eq(const T &a, const T &b, const R &... c) {
  return a == b && all_eq(b, c...);
}

int fnv_hash(const std::string &s);
}
