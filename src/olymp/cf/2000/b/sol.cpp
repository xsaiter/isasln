#include <bits/stdc++.h>

using namespace std;

bool solve(int n, const vector<int> &a) {
  if (n < 3) {
    return true;
  }
  vector<int> b(n + 1, 0);  
  b[a[0]] = 1;
  for (int i = 1; i < n; ++i) {
    b[a[i]] = 1;
    if ((a[i] > 1 && b[a[i] - 1] == 1) ||
        (a[i] < n && b[a[i] + 1] == 1)) {
      continue;
    }    
    return false;
  }
  return true;
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
    cout << (solve(n, a) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}