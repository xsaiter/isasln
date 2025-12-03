#include <bits/stdc++.h>

using namespace std;

bool solve(string &a, string &b) {
  int n = (int)a.size();
  int m = (int)b.size();
  if (n != m) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    a[i] = tolower(a[i]);
  }
  for (int i = 0; i < m; ++i) {
    b[i] = tolower(b[i]);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  string a, b;
  cin >> a >> b;
  cout << (solve(a, b) ? "Yes" : "No") << endl;
  return 0;
}