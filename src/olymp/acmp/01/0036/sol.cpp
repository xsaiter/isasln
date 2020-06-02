#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x) {
  if (x == 1 || x == 2) {
    return true;
  }
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int to = 2 * n;
  int res = 0;
  for (int i = n + 1; i < to; ++i) {
    if (is_prime(i)) {
      ++res;
    }
  }
  cout << res << endl;
  return 0;
}