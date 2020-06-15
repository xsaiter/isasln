#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, n, x;
  cin >> a >> b >> c >> n; 
  int res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    if (x > b && x < c) {
      ++res;
    }
  }    
  cout << res << endl;
  return 0;
}