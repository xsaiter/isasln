#include <bits/stdc++.h>

using namespace std;

int solve(int l, int r) {
  int d = r - l;
  if (d == 0) {
    return 1;
  }
  if (d == 1) {
    return 2;
  }    
  int res = 1;
  int cur = l;
  for (int i = 1; i < d; ++i) {
    cur += i;
    if (cur > r) {
      cur -= i;
      break;
    }
    if (cur == r) {
      ++res;
      break;
    }
    ++res;
  }  
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    cout << solve(l, r) << '\n';
  }
  cout << endl;
  return 0;
}