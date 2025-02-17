#include <bits/stdc++.h>

using namespace std;

using LL = long long;

int solve(int n, vector<LL> &a) {
  int res = 0;
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}