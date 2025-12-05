#include <bits/stdc++.h>

#define PI 3.14159265358979323846

using namespace std;

double solve(int n) {
  if (n == 2) return 1;  
  int m = 2 * n;
  int k = (m - 4) / 4;
  double fi = ((m - 2) * PI) / m;
  double a = fi - PI / 2;
  double res = cos(a);
  for (int i = 0; i < k - 1; ++i) {
    a = fi - (PI / 2 - a) - PI / 2;
    res += cos(a);
  }
  res *= 2;
  res += 1;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << setprecision(9) << fixed << solve(n) << "\n";
  }
  cout << endl;
  return 0;
}