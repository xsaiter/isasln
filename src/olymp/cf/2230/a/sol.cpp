#include <bits/stdc++.h>

using namespace std;
using L = long long;

L solve(L n, L a, L b) {    
  if (n <= 3) {
    return min(n * a, b);
  } 
  L r = n % 3;
  L m = (n - r) / 3;
  L x = min(b * m + r * a, n * a);  
  L y = b * m + b;
  return min(x, y);
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    L n, a, b;
    cin >> n >> a >> b;
    cout << solve(n, a, b) << '\n';
  }
  cout << endl;
  return 0;
}