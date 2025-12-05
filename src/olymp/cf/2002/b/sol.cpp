#include <bits/stdc++.h>

using namespace std;

bool eq_vec(int n, const vector<int> &a, const vector<int> &b) {
  for (int i = 0 ;i < n; ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

char solve(int n, vector<int> &a, vector<int> &b) {
  bool eq = eq_vec(n, a, b);
  if (eq) {
    return 'B';
  }
  reverse(begin(a), end(a));
  eq = eq_vec(n, a, b);
  if (eq) {
    return 'B';
  }
  return 'A';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
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
    cout << (solve(n, a, b) == 'A' ? "Alice" : "Bob") << '\n';
  }
  cout << endl;
  return 0;
}