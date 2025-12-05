#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, int k) {  
  return min(n, k) * min(m, k);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    cout << solve(n, m, k) <<  '\n';
  }
  cout << endl;
  return 0;
}