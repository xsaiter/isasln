#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

#define All(c) begin(c), end(c)

int gcd(int a, int b) {
  while (b != 0) {
    int c = a % b;
    a = b;
    b = c;
  }
  return abs(a);
}

int lcm(int a, int b) {
  int c = gcd(a, b);
  return (a * b) / c;
}

int main() {
  int a, b;
  cin >> a >> b;
  int res = lcm(a, b);
  cout << res << endl;
  return 0;
}