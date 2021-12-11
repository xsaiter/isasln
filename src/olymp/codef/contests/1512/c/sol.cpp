#include <bits/stdc++.h>

using namespace std;

bool solve(string &s, int a, int b) {
  int n = a + b;
  int i = 0, j = n - 1;  
  vector<int> pos;
  while (i < j) {
    if (s[i] == '?' && s[j] == '?') {
      pos.push_back(i);      
    } else if (s[i] != '?' && s[j] != '?') {
      if (s[i] != s[j]) {
        return false;
      }
    } else {
      if (s[i] == '?') {        
        s[i] = s[j];        
      } else if (s[j] == '?') {        
        s[j] = s[i];
      }
    }
    ++i; --j;
  }  
  for (int k = 0; k < n; ++k) {
    if (s[k] == '0') --a;
    else if (s[k] == '1') --b;
  }
  int m = (int)pos.size();
  bool suc = true;
  for (int k = 0; k < m; ++k) {
    if (a >= 2) {
      s[pos[k]] = '0'; s[n - 1 - pos[k]] = '0';
      a -= 2;
    } else if (b >= 2) {
      b -= 2;
      s[pos[k]] = '1'; s[n - 1 - pos[k]] = '1';
    } else {
      suc = false;
      break;
    }
  }  
  return (suc && a == 0 && b == 0);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    bool can = solve(s, a, b);
    cout << (can ? s : "-1") << '\n';
  }
  cout << endl;
  return 0;
}