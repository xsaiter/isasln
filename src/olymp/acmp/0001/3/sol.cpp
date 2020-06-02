#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 n;
  cin >> n;
  i64 x = (n - 5) / 10;
  i64 y = x * (x + 1);
  i64 res = y * 100 + 25;
  cout << res << endl;
  return 0;
}