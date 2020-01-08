#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using vi = vector<int>;

int main() {
  int tt;
  cin >> tt;
  for (int t = 0; t < tt; ++t) {
    int n;
    cin >> n;
    vi a(n);
    i64 s = 0;
    i64 x = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      s += a[i];
      x ^= a[i];
    }
    if (s == 2 * x) {
      printf("0\n\n");
    } else {
      i64 e = 1e17;
      if (s % 2 != 0) {
        e += 1;
      }
      s += e;
      x ^= e;
      i64 d = 2 * x - s;
      assert(d % 2 == 0);
      i64 r = d / 2;
      printf("3\n%lld %lld %lld\n", e, r, r);
    }
  }
  return 0;
}