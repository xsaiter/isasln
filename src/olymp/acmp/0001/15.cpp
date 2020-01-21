#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

#define All(c) begin(c), end(c)

int main() {
  int n;
  cin >> n;
  int res = 0;
  int v = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> v;
      if (j > i) {
        res += v;
      }
    }
  }
  cout << res << endl;
  return 0;
}