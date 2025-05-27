#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;  
  int rp = 0, rk = 0, rv = 0;
  bool found = false;
  for (int p = 2; p < n; ++p) {
    for (int k = 2; k < p; ++k) {
      int np = p;
      int nk = k;
      int nv = n - nk - np;
      
      int d = nk + nv;            
      np -= d;
      if (np < 0) {
        continue;
      }
      nk *= 2;
      nv *= 2;

      d = np + nv;
      nk -= d;
      if (nk < 0) {
        continue;
      }
      np *= 2;
      nv *= 2;

      d = np + nk;
      nv -= d;
      if (nv < 0) {
        continue;
      }
      np *= 2;
      nk *= 2;
      if (np == nk && nk == nv) {
        rp = p;
        rk = k;
        rv = n - rp - rk;
        found = true;
        break;
      }
    }
    if (found) {
      break;
    }
  }
  cout << rp << " " << rv << " " << rk << endl;
  return 0;
}