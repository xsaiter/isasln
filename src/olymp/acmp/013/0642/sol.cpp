#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    if (s >= a[i]) {
      s -= a[i];
      ans += 1;
    } else {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}