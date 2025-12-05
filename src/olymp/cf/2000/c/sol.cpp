#include <bits/stdc++.h>

using namespace std;

bool solve(int n, const vector<int> &a, const string &s) {
  int len = (int)s.size();
  if (len != n) {
    return false;
  }
  map<int, char> p;
  map<char, int> q;  
  for (int i = 0; i < n; ++i) {
    if (p.find(a[i]) != p.end()) {
      if (p[a[i]] != s[i]) {
        return false;
      }
    } else {
      p.insert({a[i], s[i]});
    }
    if (q.find(s[i]) != q.end()) {
      if (q[s[i]] != a[i]) {
        return false;
      }
    } else {
      q.insert({s[i], a[i]});
    }    
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int m;
    cin >> m;
    vector<string> b(m);
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
      cout << (solve(n, a, b[i]) ? "YES" : "NO") << '\n';
    }    
  }
  cout << endl;
  return 0;
}