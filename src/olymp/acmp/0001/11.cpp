#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

int main() {
  int k, n;
  cin >> k >> n;
  vi a(n, 0);
  int res = 0;
  if (n < k) {
    res = pow(2, k - 1);
  } else {
    for (int i = 0; i < n; ++i) {
      if (i < k) {
        a[i] = pow(2, i);
      } else {
        for (int j = 0; j < i; ++j) {
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}