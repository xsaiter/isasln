#include <bits/stdc++.h>

using namespace std;

// 1 2 3 4 5 6 7 8 9 11
// 1 3 5 7 9 11 - ok
int solve(int n, int m) {
  int ans = 0;
  while (true) {
    int r = m % 2;
    if (r == 0) {
      return m / 2;
    } else {
      n = (n + 1) / 2;
    }
  }  
  return -1;
}

int main() {
  int n, m;
  cin >> n >> m;
  cout << solve(n, m) << endl;
  return 0;
}