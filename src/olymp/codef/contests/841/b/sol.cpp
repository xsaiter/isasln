#include <bits/stdc++.h>

using namespace std;
using R = long long;

R sum_range(const vector<R> &s, int n, int head, int tail) {
  if (head < 0)
    return s[tail - 1];
  return s[tail - 1] - s[head];
}

int solve(vector<R> &s, vector<int> &a, int n) {
  if (s[n - 1] % 2 == 1)
    return 1;
  for (int i = n - 2; i >= 0; --i) {
    if (s[i] % 2 == 1) {
      break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<R> s(n);
  s[0] = a[0];
  for (int i = 1; i < n; ++i) {
    s[i] = s[i - 1] + a[i];
  }
  cout << (solve(s, a, n) == 1 ? "First" : "Second") << endl;
  // n = c + n
  // c = c + c
  // c = n + n
  return 0;
}