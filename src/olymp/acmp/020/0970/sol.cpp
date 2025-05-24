#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &a) {
  if (a[0] + a[1] == a[2]) {
    return true;
  }
  if (a[0] + a[2] == a[1]) {
    return true;
  }
  if (a[1] + a[2] == a[0]) {
    return true;
  }
  return false;
}

int main() {
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  cout << (solve(a) ? "YES" : "NO") << endl;
  return 0;
}