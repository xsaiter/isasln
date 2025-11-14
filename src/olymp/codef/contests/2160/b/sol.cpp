#include <bits/stdc++.h>

using namespace std;

using L = long long;

vector<L> solve(int n, vector<L>& b) {
  vector<L> a(n);
  a[0] = 1;
  vector<int> c(n + 1);
  c[1] = 1;
  for (int i = 1; i < n; ++i) {

  }
  return a;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<L> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    vector<L> a = solve(n, b);
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}