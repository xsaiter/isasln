#include <bits/stdc++.h>

using namespace std;

using T = double;

constexpr T eps = pow(10, -6);
constexpr T speed = 50.0;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  T len = 0.0;
  for (int i = 0; i < n - 1; ++i) {
    T d = sqrt(pow(x[i + 1] - x[i], 2) + pow(y[i + 1] - y[i], 2));
    len += d;
  }
  T res = k * len / speed;
  printf("%.9lf", res);
  return 0;
}