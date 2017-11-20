#pragma once

#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <memory>

#include "graphs/graph.hh"
#include "graphs/paths.hh"

namespace isa {
template <class Input, class State = int> class dfa_s {
public:
  dfa_s(State start_state) : start_state_(start_state), state_(start_state_) {}

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

class nfa_regex_s {
public:
  using graph_u = isa::graph_i_s<isa::directed_s::directed>;

  nfa_regex_s(const std::string &re, int m, const graph_u &g)
      : re_(re), m_(m), g_(g) {}

  bool accept(const std::string &str) const {
    std::set<int> states;

    auto res = isa::graph_paths_dfs(g_, 0);

    for (int v = 0; v < g_.nv(); ++v) {
      if (res.has_path_to(v)) {
        states.insert(v);
      }
    }

    const auto n = str.size();

    for (auto i = 0; i < n; ++i) {
      std::set<int> next_states;

      for (auto s : states) {
        if (s < m_) {
          if (re_[s] == str[i]) {
            next_states.insert(i);
          }
        }
      }

      states.clear();

      for (auto s : next_states) {
        auto r = isa::graph_paths_dfs(g_, s);
        for (int j = 0; j < g_.nv(); ++j) {
          if (r.has_path_to(j)) {
            states.insert(j);
          }
        }
      }
    }

    return std::any_of(states.begin(), states.end(),
                       [&](const auto &s) { return s == m_; });
  }

private:
  std::string re_;
  int m_;
  graph_u g_;
};

nfa_regex_s make_nfa_regex(const std::string &re) {
  const int m = re.size();

  nfa_regex_s::graph_u g(m + 1);

  std::stack<int> pos;

  for (int i = 0; i < m; ++i) {
    char c = re[i];

    if (c == '(') {
      pos.push(i);
    } else if (c == '*') {
      if (re[i - 1] != ')') {
        g.add_edge(i - 1, i);
        g.add_edge(i, i - 1);
      } else {
        while (!pos.empty()) {
          auto t = pos.top();
          pos.pop();
          if (re[t] == '(') {
            g.add_edge(i, t);
            g.add_edge(t, i);
            break;
          }
        }
      }
    }

    if (i > 0) {
      g.add_edge(i - 1, i);
    }
  }

  return nfa_regex_s(re, m, g);
}
}
