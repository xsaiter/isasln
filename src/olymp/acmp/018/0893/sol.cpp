#include <bits/stdc++.h>

using namespace std;

using L = long long; 

L solve(L n) {
  if (n < 3) {
    return n;
  }
  L r = 1;
  for (int k = n - 2; k <= n; ++k) {
    r *= k;
  }
  return r;
}

int main() {
  L n;
  cin >> n;  
  cout << solve(n) << endl;
  return 0;
}