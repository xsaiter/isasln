#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a, vector<int> &b) {
  int pos = -1;
  int cur = -1e9;
  for (int i = 0; i < n; ++i) {
    int x = a[i] * b[i];
    if (x > cur) {
      cur = x;
      pos = i + 1;
    }
  }
  return pos;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  cout << solve(n, a, b) << endl;
  return 0;
}