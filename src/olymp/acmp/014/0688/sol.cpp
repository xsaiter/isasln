#include <bits/stdc++.h>

using namespace std;

using L = long long;

struct P {
  L x, y;  

  L dist(const P &p) const {  
    return (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y);
  }
};

int main() {
  P a;
  cin >> a.x >> a.y;
  P b;
  cin >> b.x >> b.y;
  int n;
  cin >> n;
  vector<P> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].x >> v[i].y;
  }  
  int j = -1;
  for (int i = 0; i < n; ++i) {
    L aa = 4L * v[i].dist(a);   
    L bb = v[i].dist(b);    
    if (aa <= bb) {
      j = i + 1;
      break;
    }
  }
  if (j == -1) {
    cout << "NO";
  } else {
    cout << j;
  }
  cout << endl;
  return 0;
}