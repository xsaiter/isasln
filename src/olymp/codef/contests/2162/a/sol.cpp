#include <bits/stdc++.h>

using namespace std;

double avg(vector<int>& a, int l, int r) {
  double s = 0;
  for (int i = l; i <= r; ++i) {
    s += a[i];
  }
  return s / (double)(r - l + 1);
}

double solve(int n, vector<int>& a) {
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      ans = max(ans, avg(a, i, j));
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