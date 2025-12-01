#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b, int c, int t) {
  if (t <= a) {
    return t * b;
  }
  return a * b + (t - a) * c;
}

int main() {
  int a, b, c, t;
  cin >> a >> b >> c >> t;
  cout << solve(a, b, c, t) << endl;
  return 0;
}