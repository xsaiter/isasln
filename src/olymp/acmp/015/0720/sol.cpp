#include <bits/stdc++.h>

using namespace std;

const double EPS = 0.001;

bool eq(double a, double b) {
  return abs(a - b) < EPS;
}

struct P {
  int x, y, l;  

  double dist2() const {
    return lx() * lx() + ly() * ly();
  }

  bool inside(double r) const {
    double dd = dist2();    
    double rr = r * r;
    return dd < rr || eq(dd, rr);
  }
  
  double lx() const {
    return l * x;
  }

  double ly() const {
    return l * y;
  }
};

P new_p(int x, int y, int l) {
  return P { .x = x, .y = y, .l = l };
}

int solve(double r, int l) {
  if (l >= r) {
    return 0;
  }
  int ans = 0;
  double k = r / l;
  int m = (int)k + 1;
  for (int i = m; i >= 1; --i) {    
    P p = new_p(i, i, l);
    if (p.inside(r)) {
      ans += 4 * i * i;                  
      while (p.y > 0) {        
        P q = new_p(p.x + 1, p.y, l);
        if (q.inside(r)) {
          p = q;
          ans += q.y * 8;
        } else {
          p = new_p(p.x, p.y - 1, l);
        }         
      }
      break;
    }    
  } 
  return ans;
}

int main() {
  double r;
  cin >> r;
  int l;
  cin >> l;
  cout << solve(r, l) << endl;
  return 0;
}