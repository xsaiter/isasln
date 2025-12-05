#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, int n) {
  int res = 0;
  return res;
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
    cout << solve(a, n) << '\n';
  }
  cout << endl;
  return 0;
}