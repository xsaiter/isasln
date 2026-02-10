#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int s, int x, vector<int> &a) {
  int sum = accumulate(begin(a), end(a), 0);
  if (sum == s) {
    return true;
  }
  if (sum > s) {
    return false;
  }
  int d = s - sum;
  return d % x == 0;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, s, x;
    cin >> n >> s >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << (solve(n, s, x, a) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}