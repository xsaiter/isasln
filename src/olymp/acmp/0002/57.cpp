#include <bits/stdc++.h>
#include <boost/algorithm/clamp.hpp>

using namespace std;

struct Pt {
  int x, y;
};

const int N = 1000;
const double eps = 1e-2;
double a[N][N];

[[nodiscard]] int yt() { return 0; }

int main() {
  int n, c, p;
  cin >> n >> c >> p;

  yt();

  vector<Pt> pts(n);
  for (int i = 0; i < n; ++i) {
    cin >> pts[i].x >> pts[i].y;
  }
  Pt ptnet;
  cin >> ptnet.x >> ptnet.y;

  for (int i = 0; i < n; ++i) {
  }

  return 0;
}