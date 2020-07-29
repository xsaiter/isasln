#include <bits/stdc++.h>

using namespace std;

int get_idx(vector<int> &a, vector<int> &b, int n, int m) {
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i] == b[j]) { return i; }
      else if (a[i] < b[j]) { break; } 
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
    }
    int idx = get_idx(a, b, n, m);
    if (idx == -1) {
      cout << "NO" << "\n";
    } else {
      cout << "YES" << "\n" << "1" << " " << a[idx] << "\n";
    }
  }
  return 0;
}