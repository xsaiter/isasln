#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  int p = 0, q = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      b[i] = a[i];
    } else {
      int one = (a[i] < 0) ? -1 : 1;
      int x = abs(a[i]);
      if (x % 2 == 0) {
        b[i] = one * x / 2;
      } else {
        if (one == 1) {
          if (p % 2 == 0) {
            b[i] = one * (x + 1) / 2;
          } else {
            b[i] = one * (x - 1) / 2;
          }
          ++p;
        } else {
          if (q % 2 == 0) {
            b[i] = one * (x + 1) / 2;
          } else {
            b[i] = one * (x - 1) / 2;
          }
          ++q;
        }
      }
    }
  }
  copy(begin(b), end(b), ostream_iterator<int>(cout, "\n"));
  return 0;
}