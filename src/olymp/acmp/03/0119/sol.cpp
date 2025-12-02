#include <bits/stdc++.h>

using namespace std;

struct R {
  int h, m, s;
};

int main() {
  int n;
  cin >> n;
  vector<R> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].h >> a[i].m >> a[i].s;
  }
  auto r_cmp = [](const R &l, const R &r) {
    if (l.h == r.h) {
      if (l.m == r.m) {
        return l.s < r.s;
      }
      return l.m < r.m;
    }
    return l.h < r.h;
  };
  sort(a.begin(), a.end(), r_cmp);
  for (int i = 0; i < n; ++i) {
    cout << a[i].h << ' ' << a[i].m << ' ' << a[i].s;
    cout << '\n';
  }
  cout << endl;
  return 0;
}