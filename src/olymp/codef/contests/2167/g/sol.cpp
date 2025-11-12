#include <bits/stdc++.h>

using namespace std;

using L = long long;

L solve(int n, vector<L>& a, const vector<L>& c) {
  vector<L> dp(n);
  for (int i = 0; i < n; ++i) {
    dp[i] = c[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[i] >= a[j]) {
        dp[i] = max(dp[i], dp[j] + c[i]);
      }
    }
  }
  L su = accumulate(begin(c), end(c), 0LL);
  L mx = *max_element(begin(dp), end(dp));
  return su - mx;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<L> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<L> c(n);
    for (int i = 0; i < n; ++i) {
      cin >> c[i];
    }
    cout << solve(n, a, c) << '\n';
  }
  cout << endl;
  return 0;
}