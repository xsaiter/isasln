#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

int main() {
  int tt;
  cin >> tt;
  for (int t = 0; t < tt; ++t) {
    int n;
    scanf("%d", &n);
    vi a(n);
    for (int k = 0; k < n; ++k) {
      scanf("%d", &a[k]);
    }
    bool ok = false;
    for (int i = 0; i + 1 < n && !ok; ++i) {
      if (abs(a[i] - a[i + 1]) >= 2) {
        printf("YES\n%d %d\n", i + 1, i + 1 + 1);
        ok = true;
      }
    }
    if (!ok) {
      printf("NO\n");
    }
  }
  return 0;
}