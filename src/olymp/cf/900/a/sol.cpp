#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  int pos = 0;
  for (int i = 0; i < n; ++i) {
    if (x[i] > 0) ++pos;
  }
  bool res = pos == 1 || (n - pos) == 1 || pos == 0 || (n - pos) == 0;
  cout << (res ? "YES" : "NO") << endl;
  return 0;
}