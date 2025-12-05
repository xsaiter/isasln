#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int xk, yk;
    cin >> xk >> yk;
    int xq, yq;
    cin >> xq >> yq;
    int res = 0;
    int dx = abs(xk - xq) - 1;
    int dy = abs(yk - yq) - 1;
    
    cout << res << '\n';
  }
  cout << endl;
  return 0;
}