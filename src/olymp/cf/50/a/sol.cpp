#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int m, n;
  cin >> m >> n;
  int k = m * n;
  int rem = k % 2;
  int res = (rem == 0) ?  k / 2 : (k - 1) / 2;
  cout << res << endl;
  return 0;
}