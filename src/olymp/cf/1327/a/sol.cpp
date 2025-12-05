#include <bits/stdc++.h>

using namespace std;

using LL = long long;

bool solve(LL n, LL k) {
  LL kk = k * k;
  if (kk > n) return false;
  if (n % 2 != k % 2) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    LL n, k;
    cin >> n >> k;
    cout << (solve(n, k) ? "YES" : "NO") << "\n";
  }
  cout << endl;
  return 0;
}