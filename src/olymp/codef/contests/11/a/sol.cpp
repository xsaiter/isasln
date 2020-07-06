#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, d;
  cin >> n >> d;
  int p, c;
  cin >> p;
  int res = 0;
  for (int i = 1; i < n; ++i) {
    cin >> c;
    int q = p - c;
    if (q >= 0) {      
      int x = 1 + (q - (q % d)) / d;
      res += x;
      c += d * x;
    }    
    p = c;
  }
  cout << res << endl;
  return 0;
}