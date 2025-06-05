#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a) {
  sort(begin(a), end(a));
  int x = 0, y = 0;
  int med = n / 2;
  for (int i = 1; i <= med; ++i) {    
    x += a[i - 1];
  }
  for (int i = med + 1; i <= n; ++i) {
    y += a[i - 1];
  }
  return y - x;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(n, a) << endl;
  return 0;
}