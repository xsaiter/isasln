#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k) {
  if (n == k) return 0;
  if (n < k) return (k - n);
  if ((n + k) % 2 == 0) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << "\n";
  }
  cout << endl;
  return 0;
}