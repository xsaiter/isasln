#include <bits/stdc++.h>

using namespace std;

int solve(int n, int a, int b) {
  int res = 0;
  int p = 2 * a + b;
  if (n >= 2 * p) {
    res = 1;
  } else if (n >= p) {
    res = 2;
  } else {
    if (n > = 4 * a) {
      if (n >
    }
    
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, a, b;
  cin >> n >> a >> b;
  cout << solve(n, a, b) << endl;
  return 0;
}