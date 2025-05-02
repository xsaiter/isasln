#include <bits/stdc++.h>

using namespace std;

int solve(int n, const vector<int> &a) {
  for (int i = 0; i < n; ++i) {
    if (a[i] <= 437) {
      return i + 1;
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int res = solve(n, a);
  if (res == -1) {
    cout << "No crash";
  } else {
    cout << "Crash " << res;
  }
  cout << endl;
  return 0;
}