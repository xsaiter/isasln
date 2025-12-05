#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m) {
  if (n <= 1) return 0;
  if (n == 2) return m;
  return m * 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << "\n";
  }
  cout << endl;
  return 0;
}