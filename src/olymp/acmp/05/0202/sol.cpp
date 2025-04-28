#include <bits/stdc++.h>

using namespace std;

vector<int> solve(const string &s, const string &t) {
  vector<int> a;
  int n = (int)s.size();
  int m = (int)t.size();
  if (n < m) {
    return a;
  }
  if (n == m) {
    for (int i = 0; i < n; ++i) {
      if (s[i] != t[i]) {
        return a;
      }
    }
    a.push_back(0);
    return a;
  }  
  for (int k = 0; k <= n - m; ++k) {
    bool found = true;    
    for (int j = 0; j < m; ++j) {
      if (s[k + j] != t[j]) {          
        found = false;
        break;
      } 
    }
    if (found) {
      a.push_back(k);
    }
  }
  return a;
}

int main() {
  string s;
  cin >> s;
  string t;
  cin >> t;
  vector<int> a = solve(s, t);
  int m = (int)a.size();
  for (int i = 0; i < m; ++i) {
    cout << a[i] << " ";
  }  
  cout << endl;
  return 0;
}