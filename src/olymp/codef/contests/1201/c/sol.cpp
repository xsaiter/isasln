#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, int n) {
  int res = 0;
  sort(begin(a), end(a));
  return a[(n - 1) % 2];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }  
  cout << solve(a, n) << endl;
  return 0;
}