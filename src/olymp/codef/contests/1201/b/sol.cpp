#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &a, int n) {
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << (solve(a, n) ? "YES" : "NO") << endl;
  return 0;
}