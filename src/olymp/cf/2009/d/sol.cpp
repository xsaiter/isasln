#include <bits/stdc++.h>
 
using namespace std;
using L = long long;
 
struct P {
  int x, y;
};
 
bool is_hit(const vector<int> &a, int n, int x) {  
  if (x < 0 || n < x) {
    return false;
  }
  return a[x] == 1;
}
 
L cnt(const vector<int> &b, const vector<int> &c, int nb, int nc, int nnb) {
  L res = 0;
  for (int i = 0; i <= nc; ++i) {    
    if (c[i] == 0) {
      continue;
    }
    if (is_hit(b, nb, i)) {
      res += nnb - 1;            
    }        
    if (is_hit(b, nb, i - 1) && is_hit(b, nb, i + 1)) {      
      res += 1;
    }
  }  
  return res;
}
 
L solve(int n, vector<P> &a) {  
  vector<int> b(n + 1, 0);
  vector<int> c(n + 1, 0);
  int nb = -1, nc = -1, nnb = 0, nnc = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i].y == 0) {
      b[a[i].x] = 1;
      nb = max(nb, a[i].x);
      ++nnb;
    } else {
      c[a[i].x] = 1;
      nc = max(nc, a[i].x);
      ++nnc;
    }
  }
  return cnt(b, c, nb, nc, nnb) + 
         cnt(c, b, nc, nb, nnc);
}
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<P> a(n);
    for (int i = 0; i <n; ++i) {
      cin >> a[i].x >> a[i].y;
    }
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}