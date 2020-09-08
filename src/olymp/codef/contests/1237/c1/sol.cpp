#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y, z;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<P> ps(n);
  for (int i = 0; i < n; ++i) {
    P p;
    cin >> p.x >> p.y >> p.z;
    ps[i] = p;
  }
  return 0;
}