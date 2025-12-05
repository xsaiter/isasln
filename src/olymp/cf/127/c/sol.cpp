#include <bits/stdc++.h>

#define N 1000000

#define fi first
#define se second

using namespace std;

int t1, t2, x1, x2, t0;

int bi1(int lo, int hi, int y2) {
  if (abs(hi - lo) <= 1) {
    return -1;
  }
  int mid = (lo + hi) / 2;
  if (mid == 0) {
    return -1;
  }
  double t = (t1 * mid + t2 * y2) / (mid + y2);   
  if (t == (double)t0) { 
    return mid;
  } else if (t > t0) {
    return bi1(mid, hi, y2);
  } else {
    return bi1(lo, mid, y2);
  }  
}


int bi2(int lo, int hi, int y1) {
  if (abs(hi - lo) <= 1) {
    return -1;
  }
  int mid = (lo + hi) / 2;
  if (mid == 0) {
    return -1;
  }
  double t = (t1 * y1 + t2 * mid) / (y1 + mid); 
  if (t == (double)t0) { 
    return mid;
  } else if (t > t0) {
    return bi2(lo, mid, y1);
  } else {
    return bi2(mid, hi, y1);
  }  
}

pair<int, int> solve() {
  for (int i = x1; i > 0; --i)  {
    int y1 = bi1(1, N, i);
    if (y1 != -1 && y1 <= x1) {
      int y2 = bi2(1, N, y1);
      if (y2 != -1 && y2 <= x2) {
        return {y1, y2};
      }
    }
  }
  return {-1, -1};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);  
  cin >> t1 >> t2 >> x1 >> x2 >> t0;  
  auto res = solve();
  cout << res.fi << " " << res.se << endl;
  return 0;
}