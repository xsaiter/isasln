#include <bits/stdc++.h>

using namespace std;

struct Seg {
  int a, b;
};

Seg make_seg(int x) {
  int a;
  if (x % 2 == 0) {
    a = x / 2;
  } else {
    a = (x + 1) / 2;
  }
  int b = x;
  return Seg {.a = a, .b = b};
}

int main() {
  int a, b;
  cin >> a >> b;    
  Seg p = make_seg(a);
  Seg q = make_seg(b);  
  int ma = min(p.b, q.b);
  int mi = max(p.a, q.a);
  cout << mi << ' ' << ma << endl;
  return 0;
}