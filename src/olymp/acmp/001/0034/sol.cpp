#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int t;
  int r = 0;
  int d = n - k;
  for (int i = 0; i < d && r == 0; ++i) {
    for (int j = i + 1; j < d && r == 0; ++j) {
      for (t = 0; t < k; ++t) {
        if (s[i + t] != s[j + t]) {
          break;
        }
      }
      if (t == k) {
        ++r;
      }
    }
  }
  if (r > 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;
  return 0;
}