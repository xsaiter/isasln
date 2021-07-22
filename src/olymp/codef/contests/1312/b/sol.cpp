#include <bits/stdc++.h>

using namespace std;
// j - a[j] != i - a[i]
vector<int> solve(vector<int> &a, int n) {
  vector<int> b(n);
  vector<int> c(n, 0);
  for (int i = 0; i < n; ++i) {
    c[a[i]] = 1;
  }
  return b;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b = solve(a, n);
    copy(begin(b), end(b), ostream_iterator<int>(cout, " "));
    cout << '\n';
  }
  cout << endl;
  return 0;
}