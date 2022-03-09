#include <bits/stdc++.h>

using namespace std;

int cnt2(int n) {
  int x = n % 2;
  return (n - x) / 2;
}

int solve(int a, int b, int c) {  
  int rb = min(b, cnt2(c));
  b -= rb;
  if (b < 2) return 3 * rb;
  int ra = min(a, cnt2(b));
  return 3 * (rb + ra);  
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << '\n';
  }
  cout << endl;
  return 0;
}