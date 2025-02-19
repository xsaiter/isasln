#include <bits/stdc++.h>

using namespace std;

struct Rect {
  int w, h;
};

int solve(int n, vector<Rect> &rr) {  
  sort(begin(rr), end(rr), [](const Rect &a, const Rect &b) {
    if (a.w == b.w) {
      return a.h < b.h;
    }
    return a.w < b.w;
  });

  int res = 0;
  for (int i = 0; i < n; ++i) {

  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<Rect> rr(n);
    for (int i = 0; i < n; ++i) {
      cin >> rr[i].w >> rr[i].h;
    }
    cout << solve(n, rr) << '\n';
  }
  cout << endl;
  return 0;
}