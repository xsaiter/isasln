#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int res = 0;
  int m = 0, mj = 0, pmj = 0;
  int i = 0;
  while (i < n) {
    m = a[i];
    for (int j = i; j < n; ++j) {
      if (a[j] > m) {
        m = a[j];
        mj = j;
      }
    }
    res += m * (mj - pmj + 1);
    ++mj;
    i = mj;
    pmj = mj;
  }
  cout << res << endl;
  return 0;
}