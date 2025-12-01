#include <bits/stdc++.h>

using namespace std;

using L = long long;

int main() {
  L n, m, d, k;
  cin >> n >> m >> d >> k;
  L ans = (n + m) * d * k - n * m * d * d;
  cout << ans << endl;
  return 0;
}