#include <bits/stdc++.h>

using namespace std;

bool solve(string &s, int a, int b) {
  int n = a + b;
  int i = 0, j = n - 1, cnt = 0;  
  while (i < j && a >= 0 && b >= 0) {
    if (s[i] == '?' && s[j] == '?') {
      ++cnt;
    } else if (s[i] != '?' && s[j] != '?') {
      if (s[i] != s[j]) {
        return false;
      }
    } else {
      if (s[i] == '?') {
        if (s[j] == '0') --a; else --b;
        s[i] = s[j];        
      } else if (s[j] == '?') {
        if (s[i] == '0') -- a; else --b;
        s[j] = s[i];
      }
    }
    ++i; --j;
  }  
  while (cnt--) {
    if (a > 2) a -= 2;
    else if (b > 2) b -= 2;
  }
  if (cnt == 0 && a == 0 && b == 0) return true;
  return false;
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