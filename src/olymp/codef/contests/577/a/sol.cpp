#include <bits/stdc++.h>

using namespace std;

int solve(int n, int x) {
  int res = 0;  
  for (int p = 1; p <= n; ++p) {
    if (x % p == 0) {
      int t = x / p;
      if (t <= n) {
        ++res;
      }
    }
  }
  return res;
}

int main() {
  int n, x;
  cin >> n >> x;
  cout << solve(n, x) << endl;
  return 0;
}