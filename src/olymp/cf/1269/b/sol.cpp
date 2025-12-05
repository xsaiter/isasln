#include <bits/stdc++.h>

using namespace std;

// a[i] = (a[i] + x) mod m

int solve(int n, int m, vector<int> &a, vector<int> &b) {
  int res = 0;
  sort(a.begin(), a.end());
  sort(b.begin(). b.end());
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  cout << solve(m, m, a, b) << endl;
  return 0;
}