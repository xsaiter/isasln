#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int ne = a;
  int nf = min(b, c);
  int res;
  if (e > f) {
    res = min(ne, d) * e + min(nf, max((d - ne), 0)) * f;
  } else {
    res = min(nf, d) * f + min(ne, max((d - nf), 0)) * e;
  }
  cout << res << endl;
  return 0;
}