#include <bits/stdc++.h>

using namespace std;

int dp(int n, int k, string &s) {
  int res = 0;
  for (int i = 0; i < n; ++i) {
  }
  return res;
}

int solve(int n, string &s) {
  return dp(n, n, s);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
     int n;
     cin >> n;
     string s;
     cin >> s;
     cout << solve(n, s) << '\n';
  }
  cout << endl;
  return 0;
}
