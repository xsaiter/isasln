#pragma once

#include <algorithm>
#include <map>
#include <memory>
#include <set>
#include <vector>

#include "../graphs/graph.hpp"

namespace isa::parsing {
template <typename Input, typename State = int> class DFA {
public:
  explicit DFA(const State &start_state)
      : start_state_(start_state), state_(start_state_) {}

  void add_state(const State &state, bool is_final) {
    states_.insert(state);
    if (is_final) {
      final_states_.insert(state);
    }
  }

  void add_transition(const State &src, const State &dest, const Input &c) {
    auto pair = std::make_pair(src, c);
    auto i = transitions_.find(pair);
    if (i == transitions_.end()) {
      transitions_.insert(std::make_pair(pair, dest));
    }
  }

  void input(Input c) {
    auto pair = std::make_pair(state_, c);
    auto i = transitions_.find(pair);
    if (i != transitions_.end()) {
      state_ = i->second;
    }
  }

  State state() const { return state_; }

  bool is_accept() const {
    return std::any_of(final_states_.begin(), final_states_.end(),
                       [&](const auto &s) { return s == state_; });
  }

private:
  State start_state_;
  State state_;
  std::set<State> states_;
  std::set<State> final_states_;
  std::map<std::pair<State, Input>, State> transitions_;
};
} // namespace isa::parsing
