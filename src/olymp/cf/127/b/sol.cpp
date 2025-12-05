#include <bits/stdc++.h>

#define K 101

using namespace std;

int solve(vector<int> &a, int n) {
  if (n < 4) {
    return 0;
  }
  vector<int> b(K, 0);
  for (int i = 0; i < n; ++i) {
    ++b[a[i]];
  }
  int p = 0;
  for (int i = 1; i < K; ++i) {
    p += (b[i] - (b[i] % 2)) / 2;
  }
  return p / 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(begin(a), end(a));
  int res = solve(a, n);
  cout << res << endl;
  return 0;
}