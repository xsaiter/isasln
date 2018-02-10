#pragma once

#include <functional>
#include <vector>
#include <string>
#include <memory>

#include "utils.hh"

namespace isa {
template <typename T> class bloom_filter_s {
public:
  using func_u = std::function<int(const T &)>;

  bloom_filter_s(std::size_t capacity, std::initializer_list<func_u> funcs)
      : capacity_(capacity), bits_(capacity), funcs_(funcs) {}

  void add(const T &item) {
    const std::size_t n = funcs_.size();

    for (std::size_t i = 0; i < n; ++i) {
      const std::size_t pos = get_pos(i, item);
      bits_[pos] = true;
    }
  }

  bool contains(const T &item) const {
    const std::size_t n = funcs_.size();

    for (std::size_t i = 0; i < n; ++i) {
      const std::size_t pos = get_pos(i, item);
      if (!bits_[pos]) {
        return false;
      }
    }

    return true;
  }

private:
  std::size_t capacity_;
  std::vector<bool> bits_;
  std::vector<func_u> funcs_;

  inline std::size_t get_pos(std::size_t i, const T &item) const {
    return funcs_[i](item) % capacity_;
  }
};

using bloom_filter_str_u = bloom_filter_s<std::string>;

std::unique_ptr<bloom_filter_str_u>
make_bloom_filter_str(std::size_t capacity) {
  return std::make_unique<bloom_filter_str_u>(
      capacity, std::initializer_list<bloom_filter_str_u::func_u>{&fnv_hash});
}
}
