#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

#define All(c) begin(c), end(c)

int main() {
  int n;
  cin >> n;
  --n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  bool ok = false;
  int res = n;
  for (int s = 1; s < n && !ok; ++s) {
    if (n % s == 0) {
      ok = true;
      int k = n / s;
      for (int i = 0; i < (k - 1) && ok; ++i) {
        for (int t = 0; t < s && ok; ++t) {
          if (a[i * s + t] != a[(i + 1) * s + t]) {
            ok = false;
          }
        }
      }
      if (ok) {
        res = s;
      }
    }
  }
  cout << res << endl;
  return 0;
}