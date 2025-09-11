#include <bits/stdc++.h>

using namespace std;

int proc(int x) {
  int ans = 0;
  while (x != 2) {
    if (x % 2 == 0) {
      x /= 2;
    } else {
      x = 3 * x + 1;
    }
    ++ans;
  }
  return ans;
}

int main() {
  int p, k;
  cin >> p >> k;  
  int res = 0;
  while (p <= k) {
    res += proc(p);
    ++p;
  }
  cout << res << endl;
  return 0;
}