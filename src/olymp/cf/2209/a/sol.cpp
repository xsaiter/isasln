#include <bits/stdc++.h>

using namespace std;

using L = long long;

L solve(int n, int c, int k, vector<int> &a) {
  L ans = 0;
  sort(a.begin(), a.end());
  int pos = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] < c) {
      c += 
    }
  }
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, c, k, a) << '\n';
  }
  cout << endl;
  return 0;
}