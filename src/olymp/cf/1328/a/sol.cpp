#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b) {
  if (a == b) return 0;
  if (a < b) return b - a;
  int rem = a % b;
  if (rem == 0) return 0;
  return b - rem;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << "\n";
  }
  cout << endl;
  return 0;
}