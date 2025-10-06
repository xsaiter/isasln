#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b, int c, int k) {
  int res = 0;
  return res;
}

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int n = a + 2 * b + 3 * c;
  int rem = n % k;
  int ans = (n - rem) / k;
  cout << ans << endl;
  return 0;
}