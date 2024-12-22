#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b) {
  if (a >= b) {
    return a;
  }
  int x = b - a;
  if (x <= 0) {
    return 0;
  }
  int res = a - x;
  if (res < 0) {
    return 0;
  }  
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << '\n';
  }
  cout << endl;
  return 0;
}