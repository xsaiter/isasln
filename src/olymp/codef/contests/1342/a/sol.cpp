#include <bits/stdc++.h>

using namespace std;

using L = long long;

L solve(L x, L y, L a, L b) {  
  if (x == 0 && y == 0) return 0;
  if (x < y) {
    L t = y;
    y = x;
    x = t;
  }
  if (a + a <= b) {
    return (x + y) * a;
  }  
  return y * b + (x - y) * a; 
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    L x, y;
    cin >> x >> y;
    L a, b;
    cin >> a >> b;
    cout << solve(x, y, a, b) << '\n';
  }
  cout << endl;
  return 0;
}

