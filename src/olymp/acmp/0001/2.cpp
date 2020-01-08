#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  int n;
  cin >> n;
  int res = 1;
  if (n != 0) {
    bool pos = true;
    if (n < 0) {
      pos = false;
      n = -n;
    }
    res = n * (n + 1) / 2;
    if (!pos) {
      res = -res;
      ++res;
    }
  }
  cout << res;
  return 0;
}