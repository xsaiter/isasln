#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int m, const vector<int> &a) {
  int s = 0;
  for (int i = 0; i < n; ++i) {
    s += a[i];
  }
  return s % m == 0;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << (sovle(n, m, a) ? "YES" : "NO") << endl;
  return 0;
}