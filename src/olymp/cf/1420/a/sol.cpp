#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &a, int n) {
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] <= a[i + 1]) {
      return true;
    }
  }
  return false;
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
    for (int i = 0;  i <n; ++i) {
      cin >> a[i];
    }
    cout << (solve(a, n) ? "YES" : "NO") << "\n";
  }
  cout << endl;
  return 0;
}