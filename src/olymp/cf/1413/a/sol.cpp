#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> &a, int n) {
  vector<int> b(n);
  for (int i = 0; i < n - 1; i += 2) {
    int x = a[i];
    int y = a[i + 1];
    b[i] = y;
    b[i + 1] = -x;
  }
  return b;
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
    vector<int> b = solve(a, n);
    copy(begin(b), end(b), ostream_iterator<int>(cout, " "));
    cout << '\n';
  }
  cout << endl;
  return 0;
}