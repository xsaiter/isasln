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

struct key_s {
  int a;
  char c;
};

bool operator==(const key_s &lhs, const key_s &rhs) {
  return lhs.a == rhs.a && lhs.c == rhs.c;
}

struct key_cmp_s {
  bool operator()(const key_s &lhs, const key_s &rhs) const {
    if (lhs.a < rhs.a) {
      return true;
    } else if (lhs.a > rhs.a) {
      return false;
    }
    return lhs.c < rhs.c;
  }
};

using set_u = std::set<int>;
using set_ptr_u = std::shared_ptr<set_u>;

inline set_ptr_u make_set_ptr(std::initializer_list<int> args) {
  return std::make_shared<set_u>(args);
}

inline set_ptr_u make_set_ptr() { return make_set_ptr({}); }

class nfa_s {
public:
  nfa_s(int size) : size_(size), init_state_(0), final_state_(size - 1) {}

  int size_;
  int init_state_;
  int final_state_;
  std::map<int, set_ptr_u> eps_trans_;
  std::map<key_s, set_ptr_u, key_cmp_s> trans_;

  int size() const { return size_; }
  int init_state() const { return init_state_; }
  int final_state() const { return final_state_; }

  void add_eps_tran(int a, int b) {
    auto i = eps_trans_.find(a);
    if (i != eps_trans_.end()) {
      i->second->insert(b);
    } else {
      eps_trans_.insert({a, make_set_ptr({b})});
    }
  }

  void add_trans(int a, int b, char c) {
    key_s key{a, c};
    auto i = trans_.find(key);
    if (i != trans_.end()) {
      i->second->insert(b);
    } else {
      trans_.insert({key, make_set_ptr({b})});
    }
  }

  bool recognize(const std::string &s) {
    auto states = eps_closure(init_state_);

    for (char c : s) {
      auto move_states = move(states, c);
      states = eps_closure(move_states);
    }

    return states->find(final_state_) != states->end();
  }

  set_ptr_u move(const set_ptr_u &states, char c) const {
    auto res = make_set_ptr();

    for (auto state : *states) {
      key_s key{state, c};
      auto i = trans_.find(key);
      if (i != trans_.end()) {
        std::copy(i->second->begin(), i->second->end(),
                  std::inserter(*res, res->begin()));
      }
    }

    return res;
  }

  set_ptr_u eps_closure(int state) const {
    auto res = make_set_ptr({state});
    std::vector<bool> bits(size_, false);
    eps_closure(state, res, bits);
    return res;
  }

  void eps_closure(int state, set_ptr_u &res, std::vector<bool> &bits) const {
    if (bits[state] == true) {
      return;
    }

    auto i = eps_trans_.find(state);
    if (i != eps_trans_.end()) {
      bits[state] = true;
      res->insert(state);

      for (const int j : *(i->second)) {
        res->insert(j);
        eps_closure(j, res, bits);
        bits[j] = true;
      }
    }
  }

  set_ptr_u eps_closure(const set_ptr_u &states) const {
    auto res = make_set_ptr();

    for (int i : *states) {
      auto set = eps_closure(i);
      for (auto j : *set) {
        res->insert(j);
      }
    }

    return res;
  }
};

using nfa_ptr_u = std::shared_ptr<nfa_s>;

nfa_ptr_u make_nfa_ptr(int size) { return std::make_shared<nfa_s>(size); }

/*
 * building nfa
*/

void alt(const nfa_ptr_u &a, nfa_ptr_u &res, int offset) {
  for (auto i = a->trans_.begin(); i != a->trans_.end(); ++i) {
    for (auto j = i->second->begin(); j != i->second->end(); ++j) {
      auto a = i->first.a + offset;
      auto b = (*j) + offset;
      res->add_trans(a, b, i->first.c);
    }
  }

  for (auto i = a->eps_trans_.begin(); i != a->eps_trans_.end(); ++i) {
    for (auto j = i->second->begin(); j != i->second->end(); ++j) {
      auto a = i->first + offset;
      auto b = (*j) + offset;
      res->add_eps_tran(a, b);
    }
  }

  res->add_eps_tran(0, a->init_state() + offset);
  res->add_eps_tran(a->final_state() + offset, res->final_state());
}

nfa_ptr_u build_alt(const nfa_ptr_u &a, const nfa_ptr_u &b) {
  int size = a->size() + b->size() + 2;

  nfa_ptr_u res = make_nfa_ptr(size);

  int offset = 1;
  alt(a, res, offset);
  offset += a->size();
  alt(b, res, offset);

  return res;
}

void proc_alt(std::stack<nfa_ptr_u> &fas) {
  nfa_ptr_u b = fas.top();
  fas.pop();

  nfa_ptr_u a = fas.top();
  fas.pop();

  auto res = build_alt(a, b);

  fas.push(res);
}

void proc_char(std::stack<nfa_ptr_u> &fas, char c) {
  nfa_ptr_u res = make_nfa_ptr(2);
  res->add_trans(0, 1, 'c');
  fas.push(res);
}

void proc_concat(std::stack<nfa_ptr_u> &fas) {
  if (!fas.empty()) {
    nfa_ptr_u b = fas.top();
    fas.pop();

    nfa_ptr_u a = nullptr;

    if (!fas.empty()) {
      a = fas.top();
      fas.pop();

      nfa_ptr_u res = make_nfa_ptr(1);

      fas.push(res);

    } else {
      fas.push(b);
    }
  }
}

void proc_kleene_star(std::stack<nfa_ptr_u> &fas) {}

nfa_ptr_u build_nfa_from_regex(const std::string &re) {
  nfa_ptr_u nfa = make_nfa_ptr(2);

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
          proc_alt(fas);
        } else if (t == '(') {
          break;
        }
      }
    } else if (c == '*') {
      proc_kleene_star(fas);
    } else {
      proc_char(fas, c);
    }
  }

  return nfa;
}

/*
 * tests
*/

void test_dfa() {
  nfa_s nfa(11);

  nfa.add_trans(2, 3, 'a');
  nfa.add_trans(4, 5, 'b');
  nfa.add_trans(7, 8, 'a');
  nfa.add_trans(8, 9, 'b');
  nfa.add_trans(9, 10, 'b');

  nfa.add_eps_tran(0, 1);
  nfa.add_eps_tran(0, 7);
  nfa.add_eps_tran(1, 2);
  nfa.add_eps_tran(1, 4);
  nfa.add_eps_tran(3, 6);
  nfa.add_eps_tran(5, 6);
  nfa.add_eps_tran(6, 1);
  nfa.add_eps_tran(6, 7);

  bool ok = nfa.recognize("aaaabb");

  std::cout << ok << std::endl;
}

int main(int argc, char *argv[]) {
  auto a = make_nfa_ptr(2);

  a->add_trans(0, 1, 'a');

  auto b = make_nfa_ptr(2);
  b->add_trans(0, 1, 'b');

  auto a_or_b = build_alt(a, b);

  test_dfa();

  // auto nfa = build_nfa_from_regex("(a|b)");

  return 0;
}
