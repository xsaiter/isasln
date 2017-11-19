#pragma once

#include <map>
#include <set>
#include <vector>

#include <algorithm>

namespace isa {
template <class T> class dfa_s {
public:
  dfa_s(int start_state) : start_state_(start_state), state_(start_state_) {}

  void add_state(int state, bool is_final) {
    states_.insert(state);
    if (is_final) {
      final_states_.insert(state);
    }
  }

  void add_transition(int src, int dest, T c) {
    auto pair = std::make_pair(src, c);
    auto i = transitions_.find(pair);
    if (i == transitions_.end()) {
      transitions_.insert(std::make_pair(pair, dest));
    }
  }

  void next(T c) {
    auto pair = std::make_pair(state_, c);
    auto i = transitions_.find(pair);
    if (i != transitions_.end()) {
      state_ = i->second;
    }
  }

  int state() const { return state_; }

  bool is_accept() const {
    return std::any_of(final_states_.begin(), final_states_.end(),
                       [&](const auto &x) { return x == state_; });
  }

private:
  int start_state_;
  int state_;
  std::set<int> states_;
  std::set<int> final_states_;
  std::map<std::pair<int, T>, int> transitions_;
};
}
