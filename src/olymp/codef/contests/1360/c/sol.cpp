#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

bool solve(vi &a, int n) {
  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) ++x; else ++y;
  }
  x %= 2; y %= 2;
  if (x == 0 && y == 0) {
    return true;
  } else if (x == 1 && y == 1) {
    sort(begin(a), end(a));
    for (int i = 1; i < n; ++i) {
      if (a[i] - a[i - 1] == 1) {
        return true;
      }
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
    vi a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }    
    cout << (solve(a, n) ? "YES" : "NO") << "\n";
  }
  cout << endl;
  return 0;
}