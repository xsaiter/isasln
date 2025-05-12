#include <bits/stdc++.h>

using namespace std;

vector<int> pref_f(const string& t) {
  int m = (int)t.size();
  vector<int> a(m, 0);
  int j = 0;
  for (int i = 1; i < m; ++i) {
    while (j > 0 && t[i] != t[j]) {
      j = a[j - 1];
    }
    if (t[i] == t[j]) {
      j += 1;
    }
    a[i] = j;
  }
  return a;
}

vector<int> solve(const string& s, const string& t) {
  int n = (int)s.size();
  int m = (int)t.size();
  vector<int> pf = pref_f(t);
  int j = 0;
  vector<int> res;
  for (int i = 0; i < n; ++i) {
    while (j > 0 && s[i] != t[j]) {
      j = pf[j - 1];
    }
    if (s[i] == t[j]) {
      j += 1;
    }
    if (j == m) {
      res.push_back(i - m + 1);
      j = pf[j - 1];
    }
  }
  return res;
}

int main() {
  string s, t;
  cin >> s >> t;
  vector<int> res = solve(s, t);
  for (auto& v : res) {
    cout << v << ' ';
  }
  cout << endl;
  return 0;
}