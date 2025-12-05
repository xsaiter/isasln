#include <bits/stdc++.h>

using namespace std;
using X = long long;

X solve(X n) {
  X res = 0;
  X r = (n - 1) / 2;
  for (X i = 0; i < r; ++i) {
    int len = 4 * ((n - 2 * i) - 1); 
    res += len * (r - i);
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    X n;
    cin >> n;
    cout << solve(n) << "\n";
  }
  cout << endl;
  return 0;
}