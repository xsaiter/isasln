#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k, vector<int> &l, vector<int> &r) {
  int res = 0;
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
      cin >> l[i];
    }
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
      cin >> r[i];
    }
    cout << solve(n, k, k, r) << '\n';
  }
  cout << endl;
  return 0;
}