#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int m, int k) {
  return n * m >= k;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  cout << (solve(n, m, k) ? "YES" : "NO")  << endl;
  return 0;
}
