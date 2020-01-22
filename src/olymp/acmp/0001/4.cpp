#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

#define All(c) begin(c), end(c)

int main() {
  int a;
  cin >> a;
  int b = 9;
  int c = b - a;
  int r = a * 100 + 10 * b + c;
  cout << r << endl;
  return 0;
}