#include <bits/stdc++.h>

using namespace std;

bool mirror(const vector<int> &a, int p, int q) {
  while (p < q) {
    if (a[p] != a[q]) {
      return false;
    }
    ++p; --q;
  }
  return true;
}

vector<int> solve(int n, int k, vector<int> &a) {
  vector<int> b;

  return b;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b = solve(n, k, a);
    int m = (int)b.size();
    for (int i = 0; i < m; ++i) {
      cout << b[i] << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}