#include <bits/stdc++.h>

using namespace std;

int solve(string &s) {
  int n = (int)s.size();
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i - 1]) {
      return n - 1;
    }
  }
  return -1;
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