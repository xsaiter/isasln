#include <bits/stdc++.h>

using namespace std;

struct It {
  int x, y, x1, y1, x2, y2, x3, y3, x4, y4;

  bool inside() const {
  }
};

void show(vector<It> &a, int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d %d %d %d %d %d %d %d %d %d \n", a[i].x, a[i].y, a[i].x1, a[i].y1, a[i].x2, a[i].y2, a[i].x3, a[i].y3, a[i].x4, a[i].y4);
  }
}

int main() {
  int n;
  cin >> n;
  vector<It> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2 >> a[i].x3 >> a[i].y3 >> a[i].x4 >> a[i].y4;
  }
  int res = 0; 
  for (int i = 0 ; i < n; ++i) {
    if (a[i].inside()) {
      ++res;
    }
  }
  printf("%d", res);
  return 0;
}