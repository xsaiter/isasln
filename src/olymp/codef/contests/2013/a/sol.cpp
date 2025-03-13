#include <bits/stdc++.h>

using namespace std;

// n - count of fruits
// x - max per sec
// <= y fruits push per sec
// min time?

int solve(int n, int x, int y) {  
  int k = min(x, y);
  int res = (n - (n % k)) / k;
  if (n % k != 0) {
    ++res;
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    cout << solve(n, x, y) << '\n';
  }
  cout << endl;
  return 0;
}