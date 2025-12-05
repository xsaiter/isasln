#include <bits/stdc++.h>

using namespace std;

int calc_min(int n) {
  int k = 0, x;
  while (true) {
    x = 1 << k;
    if (x == n) { return 1; }
    if (x > n) { --k; break; }
    ++k;
  }  
  return 1 + calc(n - (1 << k));
}

bool can(int n, int t) {
  return false;
}

int main() {  
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, p;
  cin >> n >> p;
  int res = -1;
  for (int t = 1; t < 100; ++t) {    
    int x = (n - p * t);
    if (can(x, t)) {
      res = t;
      break;
    }
  }
  cout << res << endl;
  return 0;
}