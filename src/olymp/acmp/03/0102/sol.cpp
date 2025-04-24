#include <bits/stdc++.h>

using namespace std;

const int N = 3;

struct P {
  int x, y;
};

int cross_product(const P &a, const P &b, const P &c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool solve(vector<P> &tr, P &d) {
  sort(tr.begin(), tr.end(), [](const P &l, const P &r) {
    if (l.x == r.x) {
      return l.y < r.y;
    }    
    return l.x < r.x;
  });
  int cp1 = cross_product(tr[0], tr[1], d);
  int cp2 = cross_product(tr[1], tr[2], d);
  int cp3 = cross_product(tr[2], tr[0], d);
  return (cp1 >= 0 && cp2 >= 0 && cp3 >= 0) ||
         (cp1 <= 0 && cp2 <= 0 && cp3 <= 0);
}

int main() {
  vector<P> tr(N);
  cin >> tr[0].x >> tr[0].y;
  cin >> tr[1].x >> tr[1].y;
  cin >> tr[2].x >> tr[2].y;
  P d;
  cin >> d.x >> d.y;
  cout << (solve(tr, d) ? "In" : "Out") << endl;
  return 0;
}