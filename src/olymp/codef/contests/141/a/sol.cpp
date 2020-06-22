#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using M = map<char, int>;

M calc(string &s, int n) {  
  M m;
  for (int i = 0; i < n; ++i) {
    auto f = m.find(s[i]);
    if (f != m.end()) {
      (*f).se++;
    } else {
      m.insert({s[i], 1});
    }
  }
  return m;
}

bool solve(string &a, string &b, string &c) {
  int na = (int) a.size();
  int nb = (int) b.size();
  int nc = (int) c.size();
  if (na + nb != nc) {
    return false;
  }
  auto ma = calc(a, na);
  auto mb = calc(b, nb);
  auto mc = calc(c, nc);
  for (auto &x : mc) {        
    auto fa = ma.find(x.fi);
    auto fb = mb.find(x.fi);
    int ia = (fa == ma.end()) ? 0 : (*fa).se;
    int ib = (fb == mb.end()) ? 0 : (*fb).se;
    if (ia + ib != x.se) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string a, b, c;
  cin >> a >> b >> c;
  cout << (solve(a, b, c) ? "YES" : "NO") << endl;
  return 0;
}