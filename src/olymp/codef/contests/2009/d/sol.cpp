#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

int solve(int n, vector<P> &a) {
  int res = 0;
  vector<int> b, c;
  for (int i = 0; i < n; ++i) {
    if (a[i].y == 0) {
      b.push_back(a[i].x);
    } else {
      c.push_back(a[i].x);
    }
  }
  sort(begin(b), end(b));
  sort(begin(c), end(c)); 
    
  int nb = (int)b.size();
  int nc = (int)c.size();
  int p = 0, q = 0;
  while (p < nb && q < nc) {    
    ++p; ++q;
  }
  return res;
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