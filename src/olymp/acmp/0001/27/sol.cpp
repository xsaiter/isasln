#include <bits/stdc++.h>

using namespace std;

struct Pt {
  int x, y;
};

struct Rect {
  Pt p1, p2;
};

int main() {
  int w, h, n;
  cin >> w >> h >> n;

  int x1, y1, x2, y2;
  vector<Rect> rects;

  for (int i = 0; i < n; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    rects.push_back({{x1, y1}, {x2, y2}});
  }

  int **a = new int *[w];
  for (int i = 0; i < w; ++i) {
    a[i] = new int[h];
  }

  memset(a, 0, sizeof(int) * w * h);

  for (int i = 0; i < n; ++i) {
    auto r = rects[i];
    int dx = r.p2.x - r.p1.x;
    int dy = r.p2.y - r.p1.y;
  }

  for (int i = 0; i < w; ++i) {
    delete[] a[i];
  }
  delete[] a;

  return 0;
}