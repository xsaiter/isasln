#include <bits/stdc++.h>

using namespace std;

// 0 <= d <= k

int solve(int x, int y, int k) {  
  if (x == 0 && y == 0) {
    return 0;
  }
  
  return 0;	
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