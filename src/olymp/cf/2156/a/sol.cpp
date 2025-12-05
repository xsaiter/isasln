#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
  int ans = 0;
  while (n > 2) {
    int m = n % 3;
    if (m == 0) {
      ans += n / 3;
      n = n / 3;
    } else {
      ans += (n - m) / 3;
      n = n - 2 * (n - m) / 3;
    }
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << solve(n) << '\n';
  }
  cout << endl;
  return 0;
}