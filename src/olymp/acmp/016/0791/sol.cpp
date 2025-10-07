#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;

  bool ok() const {
    return ok(x) && ok(y);
  }

  bool ok(int v) const {
    return v >= 1 && v <= 8;
  }

  int num() const {
    return x + (y - 1) * 8;
  }    
};

P new_p(int x, int y) {
  return P {.x = x, .y = y};
}

P to_p(int n) {    
  int x = n % 8;  
  if (x == 0) {
    x = 8;
  }
  int y = 1 + (n - x) / 8;
  return new_p(x, y);
}

int main() {
  int n;
  cin >> n;
  P p = to_p(n);  
  P a = new_p(p.x - 1, p.y);
  P b = new_p(p.x + 1, p.y);
  P c = new_p(p.x, p.y - 1);
  P d = new_p(p.x, p.y + 1);
  vector<int> v;
  if (a.ok()) {
    v.push_back(a.num());
  }  
  if (b.ok()) {
    v.push_back(b.num());
  }  
  if (c.ok()) {
    v.push_back(c.num());
  }  
  if (d.ok()) {
    v.push_back(d.num());
  }  
  sort(begin(v), end(v));
  for (auto &e : v) {
    cout << e << ' ';
  }
  cout << endl;
  return 0;
}