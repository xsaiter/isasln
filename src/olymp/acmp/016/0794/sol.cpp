#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, int k) { 
  return n * (min(m, k - 1) + int(m / k));
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  cout << solve(n, m, k) << endl;
  return 0;
}