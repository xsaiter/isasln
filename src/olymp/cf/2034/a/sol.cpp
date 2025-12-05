#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int c = a % b;
    a = b;
    b = c;
  }
  return a;
}

int solve(int a, int b) {
  int ma = max(a, b);
  int mb = min(a, b);
  int d = gcd(ma, mb);
  return a * b / d;  
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