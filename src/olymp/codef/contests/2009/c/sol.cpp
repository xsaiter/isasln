#include <bits/stdc++.h>

using namespace std;

// 0 <= d <= k

int jumps(int k, int c) {
  if (k >= c) {
    return 1;
  }
  int d = c % k;
  int add = 0;
  if (d > 0) {
    add = 1;
  }
  return add + (c - d) / k;
}

int solve(int x, int y, int k) {  
  if (x == 0 && y == 0) {
    return 0;
  }  
  if (k >= x && k >= y) {    
    return 2;    
  }
  int nx = jumps(k, x);
  int ny = jumps(k, y); 
  return nx + ny;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y, k;
    cin >> x >> y >> k;        
    cout << solve(x, y, k) << '\n';
  }
  cout << endl;
  return 0;
}