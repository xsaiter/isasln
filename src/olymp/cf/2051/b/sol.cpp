#include <bits/stdc++.h>

using namespace std;

int cnt(int x, int a, int b, int c) {
  if (x == 0) {
    return 0;
  }
  if (x > a + b) {
    return 3;
  }
  if (x > a) {
    return 2;
  }
  return 1;
}

int solve(int n, int a, int b, int c) {
  int ans = 0;  
  if (n <= a + b + c) {
    ans += cnt(n, a, b, c);
  } else {
    int k = n % (a + b + c);
    int m = (n - k) / (a + b + c);
    ans += 3 * m;
    ans += cnt(k, a, b, c);
  }
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << solve(n, a, b, c) << '\n';
  }
  cout << endl;
  return 0;
}