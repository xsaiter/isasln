#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k, vector<int> &a) {
  int ans = 0;
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, k, a) << '\n';
  }
  cout << endl;
  return 0;
}