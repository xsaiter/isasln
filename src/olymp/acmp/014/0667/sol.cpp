#include <bits/stdc++.h>

using namespace std;

int rem(int a, int b) {
  int r = a % b;  
  if (r == 0) {
    return a / b;
  }
  return 1 + (a - r) / b;
}

int cnt(int n, int m, int k) {
  if (m < 2 || k < 3) {
    return 0;
  }
  int x_bus_for_children = 0;
  int x_adults = 0;
  int rem = n % (k - 2);
  if (rem == 0) {
    x_bus_for_children = n / (k - 2);
    x_adults = x_bus_for_children * 2;
  } else {
    x_bus_for_children = 1 + (n - rem) / (k - 2);
    x_adults = x_bus_for_children * 2;
  }
  if (x_adults > m) {
    return 0;
  }
  int rem_adults = m - x_adults;
  int y = rem(rem_adults, k);
  return x_bus_for_children + y;
}

int solve(int n, int m, int k) {
  return cnt(n, m, k);
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  cout << solve(n, m, k) << endl;
  return 0;
}