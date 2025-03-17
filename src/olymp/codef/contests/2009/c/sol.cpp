#include <bits/stdc++.h>

using namespace std;

int jumps(int k, int len) {
  if (len == 0) {
    return 0;
  }
  if (k >= len) {
    return 1;
  }
  int d = len % k;
  int add = 0;
  if (d > 0) {
    add = 1;
  }
  return add + (len - d) / k;
}

int solve(int x, int y, int k) {  
  if (x == 0 && y == 0) {
    return 0;
  }    
  int nx = jumps(k, x);
  int ny = jumps(k, y);
  if (ny >= nx) {
    return 2 * ny;
  }
  return 2 * nx - 1;
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