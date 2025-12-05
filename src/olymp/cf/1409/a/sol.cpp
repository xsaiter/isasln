#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b) {  
  int d = abs(a - b);
  int res = 0;
  for (int i = 10; i >= 1 && d != 0; --i) {
    if (i == d) {
      ++res;
      break;
    }
    if (i > d) continue;
    int r = d % i;    
    res += (d - r) / i;
    if (r == 0) break;
    d = r;
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << "\n";
  }
  cout << endl;
  return 0;
}