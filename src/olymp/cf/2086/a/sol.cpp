#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
  return 2 * n;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << solve(n) << '\n';
  }
  cout << endl;
  return 0;
}