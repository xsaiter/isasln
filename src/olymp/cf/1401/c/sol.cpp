#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &a, int n) {
  int m = *min_element(begin(a), end(a));
  vector<int> b = a;
  sort(begin(a), end(a));
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i] && a[i] % m > 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << (solve(a, n) == true ? "YES" : "NO") << "\n";
  }
  cout << endl;
  return 0;
}