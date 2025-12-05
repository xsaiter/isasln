#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;    
    int mi = min(a, b);
    int ma = max(a, b);
    int x;
    if (2 * mi == ma) {
      x = ma;
    } else if (2 * mi > ma) {
      x = 2 * mi;      
    } else {
      x = ma;      
    }
    printf("%d\n", x * x);
  }
  return 0;
}