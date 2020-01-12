#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int mi = 0, mx = 0;
  int s = (a[0] > 0) ? a[0] : 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[mi]) {
      mi = i;
    }
    if (a[i] > a[mx]) {
      mx = i;
    }
    if (a[i] > 0) {
      s += a[i];
    }
  }
  auto x = min(mi, mx);
  auto y = max(mi, mx);
  auto p = 1;
  for (auto i = x + 1; i < y; ++i) {
    p *= a[i];
  }
  cout << s << " " << p << endl;
  return 0;
}