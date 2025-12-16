#include <bits/stdc++.h>

using namespace std;

using L = long long;

L solve(int n, vector<L> &a) {
  L ans = LLONG_MIN;
  sort(a.begin(), a.end());
  for (int i = 0; i <= 5; ++i) {
    L p = 1;
    for (int j = 0; j < i; ++j) {
      p *= a[j];
    }
    for (int j = 0; j < 5 - i; ++j) {
      p *= a[n - 1 - j];
    }
    ans = max(ans, p);
  }
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<L> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }    
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}