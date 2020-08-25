#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 12;

int solve(string &s, int n) {  
  int l = INF, r = INF;
  for (int i = 0; i < n; ++i) {
   if (s[i] == '1') { l = i; break; }
  }
  for (int i = 0; i < n; ++i) {
   if (s[n - 1 - i] == '1') { r = i; break; }
  }
  int x = min(l, r);
  return (x == INF) ? n : 2 * (n - x);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(s, n)  << "\n";
  }
  cout << endl;
  return 0;
}