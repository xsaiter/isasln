#include <bits/stdc++.h>

using namespace std;

// (c - a) + (b - c)

int solve(int a, int b) {
  return b - a;
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