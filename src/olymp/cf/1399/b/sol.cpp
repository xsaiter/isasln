#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 solve(vector<int> &a, vector<int> &b, int n) {
  i64 res = 0;
  int mi_a = *min_element(begin(a), end(a));
  int mi_b = *min_element(begin(b), end(b));
  for (int i = 0; i < n; ++i) {
    res += (i64)max(a[i] - mi_a, b[i] - mi_b);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    cout << solve(a, b, n) << "\n";
  }
  cout << endl;
  return 0;
}