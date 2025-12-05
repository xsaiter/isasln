#include <bits/stdc++.h>

using namespace std;

int solve(const string &s) {  
  int n = (int)s.size();  
  bool state = s[0] == '0';
  int k = state ? 1 : 0;  
  for (int i = 1; i < n; ++i) {
    if (s[i] == '0') {
      if (!state) {
        ++k;
        state = true;
      }      
    } else {
      state = false;
    }
  }
  return min(k, 2);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << solve(s) << '\n';
  }
  cout << endl;
  return 0;
}