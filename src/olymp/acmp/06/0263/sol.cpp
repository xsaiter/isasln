#include <bits/stdc++.h>

using namespace std;

int solve(int n, int i, int j) {
  int x = abs(j - i);
  int y = min(abs(n - i), abs(i)) + min(abs(n - j), abs(j));
  return min(x, y) - 1;
}

int main() {
  int n, i, j;
  cin >> n >> i >> j;
  cout << solve(n, i, j) << endl;
  return 0;
}