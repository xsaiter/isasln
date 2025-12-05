#include <bits/stdc++.h>

using namespace std;

int solve(const string &s) {  
  int len = (int)s.size();
  if (len == 1) return 0;
  int n0 = 0, n1 = 0;
  for (int i = 0; i < len; ++i) {
    if (s[i] == '0') ++n0; else ++n1;
  }
  if (n0 < n1) {
    return n0;
  } else if (n0 > n1) {
    return n1;
  }
  return n1 - 1;
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
