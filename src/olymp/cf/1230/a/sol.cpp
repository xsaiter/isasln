#include <bits/stdc++.h>

using namespace std;

bool solve(const vector<int> &a) {
  int s = accumulate(begin(a), end(a), 0);
  int x = 0;
  for (int i = 0; i < 4; ++i) {
    x = a[i];
    if (x == s - x)
      return true;
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = i + 1; j < 4; ++j) {
      x = a[i] + a[j];
      if (x == s - x)
        return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> a(4);
  for (int i = 0; i < 4; ++i) {
    cin >> a[i];
  }
  cout << (solve(a) ? "YES" : "NO") << endl;
  return 0;
}