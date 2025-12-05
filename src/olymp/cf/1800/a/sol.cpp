#include <bits/stdc++.h>

using namespace std;

bool solve(int n, string &s) {
  int state = 0;
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (state == 0) {
      if (c == 'm' || c == 'M') {
        state = 1;
      } else {
        return false;
      }
    } else if (state == 1) {
      if (c == 'm' || c == 'M') {
        continue;
      } else if (c == 'e' || c == 'E') {
        state = 2;                  
      } else {
        return false;
      } 
    } else if (state == 2) {
      if (c == 'e' || c == 'E') {
        continue;
      } else if (c == 'o' || c == 'O') {
        state = 3;                  
      } else {
        return false;
      }
    } else if (state == 3) {
      if (c == 'o' || c == 'O') {
        continue;
      } else if (c == 'w' || c == 'W') {
        state = 4;                  
      } else {
        return false;
      }
    } else if (state == 4) {
      if (c == 'w' || c == 'W') {
        continue;
      } else {
        return false;
      }
    }
  }
  return state == 4;    
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << (solve(n, s) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}

