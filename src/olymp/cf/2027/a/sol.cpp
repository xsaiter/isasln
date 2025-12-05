#include <bits/stdc++.h>

using namespace std;

struct Rect {
  int w, h;
};

int solve(int n, vector<Rect> &r) {  
  sort(begin(r), end(r), [](const Rect &a, const Rect &b) {
    if (a.w == b.w) {
      return a.h < b.h;
    }
    return a.w > b.w;
  });

  int res = 0;  
  if (n == 1) {
    return 2 * (r[0].w + r[0].h);
  }
  int W = r[0].w;
  int H = r[0].h;
  res += 2 * W;  
  res += 2 * H;    
  for (int i = 1; i < n; ++i) {        
    int dh = r[i].h - H;    
    if (dh > 0) {
      res += 2 * dh;            
      H = r[i].h;
    }    
  }  
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<Rect> r(n);
    for (int i = 0; i < n; ++i) {
      cin >> r[i].w >> r[i].h;
    }    
    cout << solve(n, r) << '\n';    
  }
  cout << endl;
  return 0;
}