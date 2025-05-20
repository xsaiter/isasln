#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

bool solve(int n, int m, vector<P> &a) {
  
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;    
  vector<P> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  cout << (solve(n, m, a) ? "YES" : "NO") << endl;
  return 0;
}