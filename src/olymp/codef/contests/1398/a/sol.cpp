#include <bits/stdc++.h>

using namespace std;

struct Res {
  int x, y, z;
};

bool solve(vector<int> &a, int n, Res &res) {  
  if (n < 3) return false;
  res.x = 1; res.y = 2;
  for (int x = 2; x < n; ++x) {      
    if (a[x] >= a[0] + a[1]) {
      res.z = x + 1;
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    Res res;    
    if (solve(a, n, res)) {
      cout << res.x << " " << res.y << " " << res.z << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
  cout << endl;
  return 0;
}