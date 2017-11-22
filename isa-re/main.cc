#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <memory>

using key_u = std::pair<int, char>;
using set_u = std::set<int>;
using set_ptr_u = std::shared_ptr<set_u>;

inline set_ptr_u new_set_ptr() { return set_ptr_u(new set_u); }

struct nfa_s {
  int init_state_;
  set_u states_;
  set_u fin_states_;
  std::map<int, set_ptr_u> eps_trans_;
  std::map<key_u, set_ptr_u> trans_;

  bool recognize(const std::string &text) {
    set_ptr_u states = eps_closure(init_state_);

    for (char c : text) {
      auto move_states = move(states, c);
      states = eps_closure(move_states);
    }

    return std::includes(states->begin(), states->end(), fin_states_.begin(),
                         fin_states_.end());
  }

  set_ptr_u move(const set_ptr_u &states, char c) const {
    auto res = new_set_ptr();

    for (auto state : *states) {
      auto key = std::make_pair(state, c);
      auto i = trans_.find(key);
      if (i != trans_.end()) {
        std::copy(i->second->begin(), i->second->end(),
                  std::inserter(*res, res->begin()));
      }
    }

    return res;
  }

  set_ptr_u eps_closure(const set_ptr_u &states) const {
    set_ptr_u res;

    return res;
  }

  set_ptr_u eps_closure(int state) const {
    set_ptr_u res;

    return res;
  }
};

int main(int argc, char *argv[]) {
  nfa_s nfa;
  nfa.init_state_ = 0;
  nfa.states_ = {0, 1, 2, 3, 4};
  nfa.fin_states_ = {3, 4};

  nfa.eps_trans_.insert(
      std::make_pair(0, std::make_shared<set_u>(set_u{1, 3})));

  return 0;
}
