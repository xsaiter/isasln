#include <bits/stdc++.h>

using namespace std;

constexpr int M = 1000;
int a[M];

bool is_prime(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int len(int x) {
  int r = 0;
  while (x != 0) {
    auto p = x % 10;
    x = (x - p) / 10;
    ++r;
  }
  return r;
}

int main() {
  int y = len(7899);
  int m;
  cin >> m;
  for (int i = 2; i < 1000; ++i) {
    if (is_prime(i)) {
    }
  }
  return 0;
}