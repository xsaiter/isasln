#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using vi = vector<int>;
using vi64 = vector<i64>;

#define All(c) begin(c), end(c)

int main() {
  int a, b;
  cin >> a >> b;
  constexpr int n = 4;
  int ax[n];
  int bx[n];
  int i = n - 1;
  while (i >= 0) {
    ax[i] = a % 10;
    a = (a - ax[i]) / 10;
    bx[i] = b % 10;
    b = (b - bx[i]) / 10;
    --i;
  }
  int bu = 0, cu = 0;
  for (int i = 0; i < n; ++i) {
    if (ax[i] == bx[i]) {
      ++bu;
    } else {
      for (int j = 0; j < n; ++j) {
        if (ax[i] == bx[j] && ax[j] != bx[j]) {
          ++cu;
        }
      }
    }
  }
  cout << bu << " " << cu << endl;
  return 0;
}