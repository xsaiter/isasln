#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &a, int n, int k) {
  if (2 * k >= n) return false;
  int z = 0;
  for (int i = 0; i < n; ++i) {
    int j = i + 1;
    if (j % 2 > 0) {
      a[i] = j;
    } else {
      a[i] = n - z;
      ++z;
    }
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    bool can = solve(a, n, k);
    if (can) {
      cout << "-1";
    } else {
      copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}