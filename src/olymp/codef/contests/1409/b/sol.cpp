#include <bits/stdc++.h>

using namespace std;
using R = long long;

R solve(int a, int b, int x, int y, int n) {  
  R res = 0;
  int aa = a - x;
  int bb = b - y;
  if (a == b) {    
  } 
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    cout << solve(a, b, x, y, n) << "\n";
  }
  cout << endl;
  return 0;
}