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

bool operator==(const key_s &x, const key_s &y) {
  return x.a == y.a && x.c == y.c;
}

struct key_cmp_s {
  bool operator()(const key_s &x, const key_s &y) const {
    if (x.a < y.a) {
      return true;
    } else if (x.a > y.a) {
      return false;
    }
    return x.c < y.c;
  }
};

using set_u = std::shared_ptr<std::set<int>>;

inline set_u new_set(std::initializer_list<int> &&args) {
  return std::make_shared<std::set<int>>(args);
}

template <typename... R> inline set_u new_set(R... args) {
  return std::make_shared<std::set<int>>(args...);
}

inline set_u new_set() { return new_set({}); }

class nfa_s {
public:
  nfa_s(int size_) : size(size_), init(0), fin(size - 1) {}

  int size;
  int init;
  int fin;
  std::map<int, set_u> eps_trans;
  std::map<key_s, set_u, key_cmp_s> trans;

  void add_eps_tran(int a, int b) {
    auto i = eps_trans.find(a);
    if (i != eps_trans.end()) {
      i->second->insert(b);
    } else {
      eps_trans.insert({a, new_set({b})});
    }
  }

  void add_trans(int a, int b, char c) {
    key_s key{a, c};
    auto i = trans.find(key);
    if (i != trans.end()) {
      i->second->insert(b);
    } else {
      trans.insert({key, new_set({b})});
    }
  }

  bool recognize(const std::string &str) {
    auto states = eps_closure(init);

    for (char c : str) {
      auto move_states = move(states, c);
      states = eps_closure(move_states);
    }

    return states->find(fin) != states->end();
  }

private:
  set_u move(const set_u &states, char c) const {
    auto res = new_set();

    for (const auto &j : *states) {
      key_s key{j, c};
      auto i = trans.find(key);
      if (i != trans.end()) {
        res->insert(i->second->begin(), i->second->end());
      }
    }

    return res;
  }

  set_u eps_closure(const set_u &states) const {
    auto res = new_set();

    for (const auto &i : *states) {
      auto set = eps_closure(i);
      for (const auto &j : *set) {
        res->insert(j);
      }
    }

    return res;
  }

  set_u eps_closure(int state) const {
    auto res = new_set({state});

    std::vector<bool> bits(size, false);
    eps_closure(state, res, bits);

    return res;
  }

  void eps_closure(int state, set_u &res, std::vector<bool> &bits) const {
    if (bits[state] == true) {
      return;
    }

    auto i = eps_trans.find(state);
    if (i != eps_trans.end()) {
      bits[state] = true;
      res->insert(state);

      for (const auto &j : *(i->second)) {
        res->insert(j);
        eps_closure(j, res, bits);
        bits[j] = true;
      }
    }
  }
};

using nfa_u = std::shared_ptr<nfa_s>;

nfa_u new_nfa(int size) { return std::make_shared<nfa_s>(size); }

/*
 * building nfa
*/

void map_nfa(const nfa_u &x, nfa_u &res, int offset) {
  for (const auto &i : x->trans) {
    for (const auto &j : *i.second) {
      res->add_trans(i.first.a + offset, j + offset, i.first.c);
    }
  }

  for (const auto &i : x->eps_trans) {
    for (const auto &j : *i.second) {
      res->add_eps_tran(i.first + offset, j + offset);
    }
  }
}

void alt(const nfa_u &x, nfa_u &res, int offset) {
  map_nfa(x, res, offset);

  res->add_eps_tran(0, x->init + offset);
  res->add_eps_tran(x->fin + offset, res->fin);
}

nfa_u build_alt(const nfa_u &x, const nfa_u &y) {
  const int size = x->size + y->size + 2;

  nfa_u res = new_nfa(size);

  int offset = 1;
  alt(x, res, offset);

  offset += x->size;
  alt(y, res, offset);

  return res;
}

void proc_alt(std::stack<nfa_u> &fas) {
  nfa_u b = fas.top();
  fas.pop();

  nfa_u a = fas.top();
  fas.pop();

  auto res = build_alt(a, b);

  fas.push(res);
}

void proc_char(std::stack<nfa_u> &fas, char c) {
  nfa_u res = new_nfa(2);
  res->add_trans(0, 1, c);
  fas.push(res);
}

nfa_u build_concat(const nfa_u &a, const nfa_u &b) {
  int size = a->size + b->size + 1;

  auto res = new_nfa(size);

  return res;
}

void proc_concat(std::stack<nfa_u> &fas) {
  if (!fas.empty()) {
    nfa_u b = fas.top();
    fas.pop();

    nfa_u a = nullptr;

    if (!fas.empty()) {
      a = fas.top();
      fas.pop();

      nfa_u res = new_nfa(1);

      fas.push(res);

    } else {
      fas.push(b);
    }
  }
}

nfa_u build_kleene_star(const nfa_u &x) {
  const int size = x->size + 2;

  int offset = 1;

  auto res = new_nfa(size);

  map_nfa(x, res, offset);

  res->add_eps_tran(0, res->fin);
  res->add_eps_tran(0, x->init + offset);

  res->add_eps_tran(x->fin + offset, 0);
  res->add_eps_tran(x->fin + offset, res->fin);

  return res;
}

void proc_kleene_star(std::stack<nfa_u> &fas) {
  if (!fas.empty()) {
    auto a = fas.top();
    fas.pop();
    auto res = build_kleene_star(a);
    fas.push(res);
  }
}

nfa_u build_nfa_from_regex(const std::string &re) {
  nfa_u nfa = new_nfa(2);

  std::stack<nfa_u> fas;

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
  std::set<int> utt{1, 2, 3, 4};
  auto tt = new_set({5, 6, 7});

  auto a = new_nfa(2);

  a->add_trans(0, 1, 'a');

  auto b = new_nfa(2);
  b->add_trans(0, 1, 'b');

  auto ab = build_alt(a, b);

  auto ab_star = build_kleene_star(ab);

  test_dfa();

  return 0;
}
