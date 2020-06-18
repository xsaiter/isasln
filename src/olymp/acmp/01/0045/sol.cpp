#include <bits/stdc++.h>

using namespace std;

template <typename T> bool is_prime(T n) {
  for (T i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}


int prod(int x) {
  if (x < 10) {
    return x;
  }
  int res = 1;
  while (x > 1) {
    int y = x % 10;
    if (y == 0) {
      return 0;
    }
    res *= y;
    x = (x - y) / 10;
  }
  return res;
}

int solve(int n) {
  if (n < 10) {
    return n;
  }
  if (is_prime(n)) {
    return -1;
  }
  int res = -1;
  int lim = (int)pow(9, 10);
  for (int i = 1; i < lim; ++i) {
    int p = prod(i);
    if (p == n) {
      res = i;
      break;
    }
  }
  return res;
}

int main() {
  int n;
  cin >> n;  
  cout << solve(n) << endl;
  return 0;
}