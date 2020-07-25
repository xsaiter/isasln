#include <bits/stdc++.h>

using namespace std;

bool solve(const string &s, const string &t) {
  int n = (int)s.size();
  int m = (int)t.size();
  if (n != m) return false;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
      if (t[i] != 'a' && t[i] != 'e' && t[i] != 'i' && t[i] != 'o' && t[i] != 'u') {
        return false;
      } 
    } else {
      if (t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u') {
        return false;
      }
    }
  }
  return true;  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, t;
  cin >> s >> t;
  cout << (solve(s, t) ? "Yes" : "No") << endl;
  return 0;
}