#include <bits/stdc++.h>

using namespace std;
using P = pair<char, int>;
 
static constexpr int INF = INT_MAX;

vector<P> get_arr(const string &s, int n) {
  vector<P> v;
  int k = 1;
  char c = s[0];
  for (int i = 1; i < n; ++i) {
    if (s[i] != c) {
      v.push_back({c, k});
      k = 1;
      c = s[i];      
    } else {
      ++k;
    }
  }
  v.push_back({c, k});
  return v;
}

int solve(const string &s, int n) {
  if (n == 0) return 0;
  int res = INF;
  auto v = get_arr(s, n);
  int len = (int)v.size();
  for (int i = 1; i < len - 1; ++i) {
    auto a = v[i - 1].first;
    auto b = v[i].first;
    auto c = v[i + 1].first;
    if (a != b && b != c && a != c) {
      res = min(res, v[i].second);
    }    
  }
  return (res == INF) ? 0 : res + 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = (int)s.size();
    cout << solve(s, n) << "\n";
  }
  cout << endl;
  return 0;
}