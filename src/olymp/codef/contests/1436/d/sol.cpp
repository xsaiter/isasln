#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int solve(int n, vi &p, vi &a) {
  int res = 0;
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 1; i < n; ++i) {
    cin >> p[i];
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(n, p, a) << endl;
  return 0;
}
