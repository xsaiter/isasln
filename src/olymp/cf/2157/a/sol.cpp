#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a) {
  vector<int> b(n + 1);
  for (int i = 0; i < n; ++i) {
    b[a[i]] += 1;
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (b[i] > 0 && b[i] != i) {
      if (b[i] > i) {
        ans += b[i] - i;
      } else {
        ans += b[i];
      }
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
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}