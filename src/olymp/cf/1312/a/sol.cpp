#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int m) {
  if (n < m) return false;    
  return n % m == 0;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    cout << (solve(n, m) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}