#include <bits/stdc++.h>

using namespace std;
using L = long long;

L C = 1000;

struct P {
  L x, y;
  L dist() const {
    return pow(x, 2) + pow(y, 2);
  }
};

struct PP {
  P a, b;
};

bool solve(int n, L q, const vector<PP> &v) {
  if (q == 0) {
    return true;
  }
  for (int i = 0; i < n; ++i) {
     L a = v[i].a.dist();
     L b = v[i].b.dist();
     if (a == 0L) {
       if (b == 0L) {
         continue;
       } 
       return false;       
     }
     if (b == 0L) {
       return true;
     }
     a *= q * q;            
     if (b * C * C > a) {
       return false;
     }
  }
  return true;
}

int main() {  
  int n;
  double q;
  cin >> n >> q;  
  vector<PP> v(n);
  L qq = (L)(q * C + 0.5);
  for (int i = 0; i < n; ++i) {
   cin >> v[i].a.x >> v[i].a.y >> v[i].b.x >> v[i].b.y;
  }
  cout << (solve(n, qq, v) ? "Yes" : "No") << endl;
  return 0;              
}