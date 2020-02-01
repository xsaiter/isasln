#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using vi64 = vector<i64>;

int main() {
  i64 k, n;
  cin >> k >> n;
  ++n;
  vi64 a(n, 0);
  a[0] = 1;
  for (i64 i = 1; i < n; ++i) {
    for (i64 j = 1; j <= min(k, i); ++j) {
      a[i] += a[i - j];
    }
  }
  cout << a[n - 1] << endl;
  return 0;
}