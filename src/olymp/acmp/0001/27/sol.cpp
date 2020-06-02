#include <bits/stdc++.h>

using namespace std;

struct Rect {
  int x1, y1, x2, y2;
};

int main() {
  int w, h, n;
  cin >> w >> h >> n;

  int x1, y1, x2, y2;
  vector<Rect> rects;

  for (int i = 0; i < n; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    rects.push_back({x1, y1, x2, y2});
  }

  int **a = new int *[w];
  for (int i = 0; i < w; ++i) {
    a[i] = new int[h];
  }

  //memset(a, 0, sizeof(int) * w * h);

  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      a[i][j] = 0;
    }
  }

  for (int i = 0; i < n; ++i) {
    auto r = rects[i];
    for (int p = r.x1; p < r.x2; ++p) {
      for (int q = r.y1; q < r.y2; ++q) {
        a[p][q] = 1;
      }
    }
  }

  int res = 0;

  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      if (a[i][j] == 0) {
        ++res;
      }
    }
  }

  for (int i = 0; i < w; ++i) {
    delete[] a[i];
  }
  delete[] a;

  cout << res << endl;

  return 0;
}