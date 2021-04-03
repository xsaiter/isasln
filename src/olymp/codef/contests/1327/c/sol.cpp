#include <bits/stdc++.h>

using namespace std;

using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<P> s(k);
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    s[i] = {x, y};
  }
  vector<P> f(k);
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    f[i] = {x, y};
  }
  return 0;
}