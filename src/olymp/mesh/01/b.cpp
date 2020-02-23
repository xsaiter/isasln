#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  i64 lim = 1 << (n - 1);
  i64 i = 0;
  i64 res;
  for (i = 0; i < lim; ++i) {
    res = a[0];
    for (int j = 1; j < n; ++j) {
      if ((i & (1 << (j - 1))) > 0) {
        res += a[j];
      } else {
        res -= a[j];
      }
    }
    if (res == s) {
      break;
    }
  }
  if (i < lim) {
    cout << a[0];
    for (int j = 1; j < n; ++j) {
      if ((i & (1 << (j - 1))) > 0) {
        cout << "+";
      } else {
        cout << "-";
      }
      cout << a[j];
    }
    cout << "=" << s;
  } else {
    cout << "No solution";
  }
  cout << endl;
  return 0;
}