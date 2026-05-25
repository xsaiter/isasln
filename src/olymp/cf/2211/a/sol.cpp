#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a, int j) {
  if (n == 1) {
    return 1;
  }
  return 2;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    if (n == 1) {
      cout << 1;
    } else {
      for (int i = 0; i < n; ++i) {
        cout << 2 << ' ';
      }
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}