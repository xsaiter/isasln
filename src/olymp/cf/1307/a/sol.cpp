#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, int n, int d) {
  int res = a[0];
  if (n == 1) return res;
  for (int i = 1; i < n; ++i) {
    int x = a[i] * i;
    if (x <= d) {
      res += a[i];
      d -= x;
    } else {
      res += d / i;
      d = 0;
    }
    if (d == 0) break;
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(a, n, d) << "\n";
  }
  cout << endl;
  return 0;
}