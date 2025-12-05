#include <bits/stdc++.h>

using namespace std;

bool solve(int a) {
  string s = to_string(a);
  int n = (int)s.size();
  int state = 0;  
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (state == 0) {
      if (c == '1') {        
        state = 1;
      } else {
        return false;
      }
    } else if (state == 1) {
      if (c == '0') {
        state = 2;
      } else {
        return false;
      }
    } else if (state == 2) {
      if (c == '0') {
        return false;
      } else if (c == '1') {
        state = 3;
      } else {
        state = 4;
      } 
    } else {
      ++state;
    }
  }
  if (state <= 3) {
    return false;
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a;
    cin >> a;
    cout << (solve(a) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}