#include <bits/stdc++.h>

using namespace std;

using L = long long;

struct P {
  L x, y;          
};

P operator-(const P &a, const P &b) {
  return { b.x - a.x, b.y - a.y };
}

L cp(const P &a, const P &b) {
  return a.x * b.y - a.y * b.x;
}

struct Tr {
  P p1, p2, p3;  

  double area() const {                
    return fabs(cp(p2 - p1, p3 - p1)) / 2;    
  }  
};

int main() {
  Tr t;  
  cin >> t.p1.x >> t.p1.y;
  cin >> t.p2.x >> t.p2.y;
  cin >> t.p3.x >> t.p3.y;  
  printf("%.6f", t.area());
  return 0;
}