#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k) {  
  int res = n;
  if (n == k) return 1;
  if (k == 1) return n;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      if (i <= k) {
        res = min(res, n / i);
      }
      if (n / i <= k) {
        res = min(res, i);
      }
    }
  }
  return res;
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
