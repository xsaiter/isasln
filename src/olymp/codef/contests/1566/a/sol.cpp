#include <bits/stdc++.h>

using namespace std;

int solve(int n, int s) {  
  int m = n / 2 + 1;
  if (s % m == 0) {
    return s / m;
  }
  return (s - s % m) / m;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    cout << solve(n, s) << '\n';
  }
  cout << endl;
  return 0;
}