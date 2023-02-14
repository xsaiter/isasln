#include <bits/stdc++.h>

using namespace std;

int max_pref(int n, vector<int> &a) {
  int res = INT_MIN;
  int s = 0;
  for (int i = 0; i < n; ++i) {
     s += a[i];
     res = max(res, s);
  }
  return max(res, 0);
}

int solve(int n, vector<int> &r, int m, vector<int> &b) {  
  int x = max_pref(n, r);
  int y = max_pref(m, b);
  return x + y;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
      cin >> r[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
    }
    cout << solve(n, r, m, b) << '\n';
  }
  cout << endl;
  return 0;
}