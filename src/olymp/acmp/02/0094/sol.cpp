#include <bits/stdc++.h>

using namespace std;

string solve(int n, int m, int k) {
  if (n >= m) {
    return "1";
  }
  if (k >= n) {
    return "NO";
  }
  int x = 1;
  x += (m - n) / (n - k);
  if ((m % (n - k)) == 0) {
    return to_string(x);
  }
  return to_string(x + 1);
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  cout << solve(n, m, k) << endl;
  return 0;
}