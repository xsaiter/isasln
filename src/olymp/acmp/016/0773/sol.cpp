#include <bits/stdc++.h>

using namespace std;

int solve(int k, int m) {
  return k * k * m;
}

int main() {
  int k, m;
  cin >> k >> m;
  cout << solve(k, m) << endl;
  return 0;
}