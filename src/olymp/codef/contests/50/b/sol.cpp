#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using ll = long long;

inline ll calc(ll n) {
  return (n - 1) * n + n;
}

int main() {
  string s;
  cin >> s;
  ll n = (ll)s.size();
  map<char, ll> m;
  for (ll i = 0; i < n; ++i) {
    auto f = m.find(s[i]);
    if (f != m.end()) {
      (*f).se++;
    } else {
      m.insert({s[i], 1});
    }
  }
  ll res = 0;
  for (auto &e : m) {
    res += calc(e.se);
  }
  cout << res << endl;
  return 0;
}