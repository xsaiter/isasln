#include <bits/stdc++.h>

using namespace std;

using T = double;

constexpr T PI = atan(1) * 4;
constexpr T eps = 1e-6;

int n, R, r;

bool solve() {
  if (r > R) {
    return false;
  }
  if (r == R || 2 * r > R) {
    return n == 1;
  }
  T beta = 2 * asin((T)r / ((T)(R - r)));
  T m = 2 * PI / beta;
  bool eq = abs(((T)n - m)) < eps;
  return (eq ? true : (n < m));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> R >> r;
  cout << (solve() ? "YES" : "NO") << endl;
  return 0;
}