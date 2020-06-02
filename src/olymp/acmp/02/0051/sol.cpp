#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n;
  string s;
  cin >> s;
  k = s.size();
  int res = 1, v = -1;
  int m = n % k;
  if (m == 0) {
    m = k;
  }
  for (int i = 0; v != m; ++i) {
    v = (n - k * i);
    res *= v;
  }
  cout << res << endl;
  return 0;
}