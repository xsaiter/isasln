#include <bits/stdc++.h>

using namespace std;

using L = long long;

L solve(int n) {
  if (n <= 2) {    
    return 1;
  }  
  L x = 1, y = 1, tmp = 1;  
  for (int i = 3; i <= n; ++i) {
    tmp = y;
    y = x + y;
    x = tmp;            
  }
  return y;
}

int main() {
  int n;
  cin >> n;  
  ++n;
  L r = solve(n);
  cout << (r % 10) << endl;
  return 0;
}

