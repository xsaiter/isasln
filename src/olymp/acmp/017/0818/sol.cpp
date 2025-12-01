#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(begin(a), end(a));
  int ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    ans += a[i] - 1;
  }
  ans += a[n -  1];
  cout << ans << endl;
  return 0;
}