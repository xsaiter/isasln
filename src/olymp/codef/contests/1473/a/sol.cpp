#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int d, vector<int> &a) {
  sort(begin(a), end(a));  
  if (a[n - 1] <= d) {
    return true;
  }
  if (a[0] + a[1] <= d) {
    return true;
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << (solve(n, d, a) == true ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}