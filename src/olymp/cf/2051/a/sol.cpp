#include <bits/stdc++.h>

using namespace std;

int solve(int n, const vector<int> &a, const vector<int> &b) {
  int ans = a[n - 1];
  if (n == 1) {
    return ans;
  }
  for (int i = n - 2; i >= 0; --i) {
    int d = a[i] - b[i + 1];
    if (d > 0) {
      ans += d;
    }
  }
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    cout << solve(n, a, b) << '\n';
  }
  cout << endl;
  return 0;
}