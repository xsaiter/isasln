#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &r, vector<int> &b) {
  int res = -1;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  cout << solve(n, r, b) << endl;
  return 0;
}