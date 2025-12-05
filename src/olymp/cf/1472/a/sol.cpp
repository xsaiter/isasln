#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int cnt(int x) {
  int res = 0;
  while (x % 2 == 0) {
    x /= 2;
    ++res;
  }
  return 1 << res;
}

bool solve(int w, int h, int n) {  
  int x = cnt(w);
  int y = cnt(h);
  int s = x * y;
  return s >= n;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int w, h, n;
    cin >> w >> h >> n;
    cout << (solve(w, h, n) == true ? "YES" : "NO") << "\n";
  }
  cout << endl;
  return 0;
}