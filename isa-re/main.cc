#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <memory>
#include <stack>

/*
 * nfa
*/

using key_u = std::pair<int, char>;
using set_u = std::set<int>;
using set_ptr_u = std::shared_ptr<set_u>;

inline set_ptr_u make_set_ptr(std::initializer_list<int> args) {
  return std::make_shared<set_u>(args);
}

inline set_ptr_u make_set_ptr() { return make_set_ptr({}); }

class nfa_s {
public:
  nfa_s(int size, int init_state)
      : size_(size), init_state_(init_state), final_state_(size - 1) {}

  int size_;
  int init_state_;
  int final_state_;
  std::map<int, set_ptr_u> eps_trans_;
  std::map<key_u, set_ptr_u> trans_;

  int size() const { return size_; }

  int init_state() const { return init_state_; }

  int final_state() const { return final_state_; }

  void add_eps_tran(int src, int dest) {
    auto i = eps_trans_.find(src);
    if (i != eps_trans_.end()) {
      i->second->insert(dest);
    } else {
      auto e = make_set_ptr({dest});
      eps_trans_.insert(std::make_pair(src, e));
    }
  }

  void add_trans(int src, int dest, char c) {
    auto key = std::make_pair(src, c);
    auto i = trans_.find(key);
    if (i != trans_.end()) {
      i->second->insert(dest);
    } else {
      auto e = make_set_ptr({dest});
      trans_.insert(std::make_pair(key, e));
    }
  }

  bool recognize(const std::string &s) {
    set_ptr_u states = eps_closure(init_state_);

    for (char c : s) {
      auto move_states = move(states, c);
      states = eps_closure(move_states);
    }

    return states->find(final_state_) != states->end();
  }

  set_ptr_u move(const set_ptr_u &states, char c) const {
    set_ptr_u res = make_set_ptr();

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

  set_ptr_u eps_closure(int state) const {
    set_ptr_u res = make_set_ptr();
    res->insert(state);
    std::vector<bool> bits(size_, false);
    eps_closure(state, res, bits);
    return res;
  }

  void eps_closure(int state, set_ptr_u &res, std::vector<bool> &bits) const {
    if (bits[state] == true) {
      return;
    }

    auto it = eps_trans_.find(state);
    if (it != eps_trans_.end()) {
      bits[state] = true;
      res->insert(state);

      for (const int i : *(it->second)) {
        res->insert(i);
        eps_closure(i, res, bits);
        bits[i] = true;
      }
    }
  }

  set_ptr_u eps_closure(const set_ptr_u &states) const {
    set_ptr_u res = make_set_ptr();

    for (int i : *states) {
      set_ptr_u x = eps_closure(i);
      for (auto j : *x) {
        res->insert(j);
      }
    }

    return res;
  }
};

using nfa_ptr_u = std::shared_ptr<nfa_s>;

nfa_ptr_u make_nfa_ptr(int size, int init_state) {
  return std::make_shared<nfa_s>(size, init_state);
}

/*
 * building nfa
*/

void process_alt(std::stack<nfa_ptr_u> &fas) {
  nfa_ptr_u b = fas.top();
  fas.pop();

  nfa_ptr_u a = fas.top();
  fas.pop();

  int nums = a->size() + b->size() + 2;

  nfa_ptr_u res = make_nfa_ptr(nums, 0);

  fas.push(res);
}

void process_char(std::stack<nfa_ptr_u> &fas, char c) {
  nfa_ptr_u res = make_nfa_ptr(2, 0);
  res->add_trans(0, 1, 'c');
  fas.push(res);
}

void process_concat(std::stack<nfa_ptr_u> &fas) {
  if (!fas.empty()) {
    nfa_ptr_u b = fas.top();
    fas.pop();

    nfa_ptr_u a = nullptr;

    if (!fas.empty()) {
      a = fas.top();
      fas.pop();

      nfa_ptr_u res = make_nfa_ptr(1, 2);

      fas.push(res);

    } else {
      fas.push(b);
    }
  }
}

void process_kleene_star(std::stack<nfa_ptr_u> &fas) {}

nfa_ptr_u build_nfa_from_regex(const std::string &re) {
  nfa_ptr_u nfa = make_nfa_ptr(2, 1);

  std::stack<nfa_ptr_u> fas;

  std::stack<char> ops;

  std::stack<char> cs;

  for (char c : re) {
    if (c == '(') {
      ops.push(c);
    } else if (c == '|') {
      ops.push(c);
    } else if (c == ')') {
      while (!ops.empty()) {
        char t = ops.top();
        ops.pop();
        if (t == '|') {
          process_alt(fas);
        } else if (t == '(') {
          break;
        }
      }
    } else if (c == '*') {
      process_kleene_star(fas);
    } else {
      process_char(fas, c);
    }
  }

  return nfa;
}

/*
 * tests
*/

void test_dfa() {
  nfa_s nfa(11, 0);

  nfa.eps_trans_ = {{0, make_set_ptr({1, 7})},
                    {1, make_set_ptr({2, 4})},
                    {3, make_set_ptr({6})},
                    {5, make_set_ptr({6})},
                    {6, make_set_ptr({1, 7})}};

  nfa.trans_ = {{std::make_pair(2, 'a'), make_set_ptr({3})},
                {std::make_pair(4, 'b'), make_set_ptr({5})},
                {std::make_pair(7, 'a'), make_set_ptr({8})},
                {std::make_pair(8, 'b'), make_set_ptr({9})},
                {std::make_pair(9, 'b'), make_set_ptr({10})}};

  bool ok = nfa.recognize("aaaabb");

  std::cout << ok << std::endl;
}

int main(int argc, char *argv[]) {
  // test_dfa();

  auto nfa = build_nfa_from_regex("(a|b)");

  return 0;
}
