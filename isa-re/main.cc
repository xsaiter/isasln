/*
 * regexp implementation
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <memory>
#include <stack>
#include <queue>

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

template <typename... R> inline set_u new_set(R &&... args) {
  return std::make_shared<std::set<int>>(args...);
}

inline set_u new_set() { return new_set({}); }

class nfa_s {
public:
  nfa_s(int size_) : size(size_), init(0), fin(size - 1) {}

  int size;
  int init;
  int fin;
  std::map<int, set_u> etrans;
  std::map<key_s, set_u, key_cmp_s> trans;

  void add_etran(int a, int b) {
    auto i = etrans.find(a);
    if (i != etrans.end()) {
      i->second->insert(b);
    } else {
      etrans.insert({a, new_set({b})});
    }
  }

  void add_tran(int a, int b, char c) {
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
      auto next = move(states, c);
      states = eps_closure(next);
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
      const auto set = eps_closure(i);
      res->insert(set->begin(), set->end());
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

    auto i = etrans.find(state);
    if (i != etrans.end()) {
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

inline nfa_u new_nfa(int size) { return std::make_shared<nfa_s>(size); }

/*
 * building nfa
*/

void map_nfa(const nfa_u &x, nfa_u &res, int offset) {
  for (const auto &i : x->trans) {
    for (const auto &j : *i.second) {
      res->add_tran(i.first.a + offset, j + offset, i.first.c);
    }
  }

  for (const auto &i : x->etrans) {
    for (const auto &j : *i.second) {
      res->add_etran(i.first + offset, j + offset);
    }
  }
}

void alt(const nfa_u &x, nfa_u &res, int offset) {
  map_nfa(x, res, offset);

  res->add_etran(0, x->init + offset);
  res->add_etran(x->fin + offset, res->fin);
}

nfa_u build_alt(const nfa_u &x, const nfa_u &y) {
  const auto size = x->size + y->size + 2;

  nfa_u res = new_nfa(size);

  int offset = 1;
  alt(x, res, offset);

  offset += x->size;
  alt(y, res, offset);

  return res;
}

nfa_u build_concat(const nfa_u &x, const nfa_u &y) {
  const auto size = x->size + y->size - 1;

  auto res = new_nfa(size);

  int offset = 0;

  map_nfa(x, res, offset);

  offset += x->size - 1;

  map_nfa(y, res, offset);

  return res;
}

nfa_u build_kleene_star(const nfa_u &x) {
  const int size = x->size + 2;

  int offset = 1;

  auto res = new_nfa(size);

  map_nfa(x, res, offset);

  res->add_etran(0, res->fin);
  res->add_etran(0, x->init + offset);

  res->add_etran(x->fin + offset, 0);
  res->add_etran(x->fin + offset, res->fin);

  return res;
}

/*
 * convert postfix regexp to nfa
*/
nfa_u postfix_to_nfa(const std::string &postfix) {
  std::stack<nfa_u> fas;

  const int n = postfix.size();

  for (int i = 0; i < n; ++i) {
    char c = postfix[i];

    if (c == '|' || c == '*' || c == ' ') {
      if (c == ' ' || c == '|') {
        auto y = fas.top();
        fas.pop();

        auto x = fas.top();
        fas.pop();

        nfa_u r = nullptr;

        if (c == ' ') {
          r = build_concat(x, y);
        } else {
          r = build_alt(x, y);
        }

        fas.push(r);
      } else if (c == '*') {
        auto x = fas.top();
        fas.pop();

        nfa_u r = build_kleene_star(x);
        fas.push(r);
      }
    } else {
      nfa_u x = new_nfa(2);
      x->add_tran(0, 1, c);
      fas.push(x);
    }
  }

  return fas.top();
}

/*
 * convert infix regexp to postfix
*/
std::string re_to_postfix(const std::string &re) {
  std::string res;

  return res;
}

/*
 * tests
*/

inline void print_ok(bool ok, const std::string &&test_case) {
  std::cout << test_case << ":" << (ok == true ? "OK" : "ERROR") << std::endl;
}

/*
 * test: (a|b)*abb
*/
void test_1() {
  nfa_s nfa(11);

  nfa.add_tran(2, 3, 'a');
  nfa.add_tran(4, 5, 'b');
  nfa.add_tran(7, 8, 'a');
  nfa.add_tran(8, 9, 'b');
  nfa.add_tran(9, 10, 'b');

  nfa.add_etran(0, 1);
  nfa.add_etran(0, 7);
  nfa.add_etran(1, 2);
  nfa.add_etran(1, 4);
  nfa.add_etran(3, 6);
  nfa.add_etran(5, 6);
  nfa.add_etran(6, 1);
  nfa.add_etran(6, 7);

  bool res = nfa.recognize("aaaabb");

  print_ok(res, "test1");
}

/*
 * test: (abb|ba)*
*/
void test_2() {
  auto a = new_nfa(2);
  a->add_tran(0, 1, 'a');

  auto b = new_nfa(2);
  b->add_tran(0, 1, 'b');

  auto ab = build_concat(a, b);
  auto abb = build_concat(ab, b);

  auto ba = build_concat(b, a);

  auto or_ = build_alt(abb, ba);

  auto nfa = build_kleene_star(or_);

  auto res = nfa->recognize("abbabbabbbaba");

  print_ok(res, "test2");
}

/*
 * test: postfix to nfa
*/
void test_3() {
  auto nfa = postfix_to_nfa("ab b ba |*");

  auto res = nfa->recognize("abbabbabbbaba");

  print_ok(res, "test3");
}

void run_all_tests() {
  test_1();
  test_2();
  test_3();
}

int main(int argc, char *argv[]) {
  run_all_tests();
  return 0;
}
