#include <bits/stdc++.h>

using namespace std;

int len_of(int n) {
  int res = 0;
  while (n) {    
    ++res;
    n /= 10;
  }
  return res;
}

int len_diff(int x, int y) { 
  int res = 0;
  int len = len_of(x);
  for (int i = 0; i < len; ++i) {
    int mx = x % 10;
    int my = y % 10;
    if (mx != my) ++res;
    x = (x - mx) / 10;
    y = (y - my) / 10;    
  }
  return res;
}

int solve(int n) {
  int k = n % 7;
  if (k == 0) return n;
  
  int len_n = len_of(n);
  
  int x = n - k;
  int len_x = len_of(x);
  
  int y = n + 7 - k;
  int len_y = len_of(y);

  int xx = abs(len_x - len_n);
  int yy = abs(len_y - len_n);

  if (xx < yy) return x;
  else if (xx > yy) return y;
  
  int diff_x = len_diff(x, n);
  int diff_y = len_diff(y, n);

  if (diff_x < diff_y) return x;
  return y;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << solve(n) << '\n';
  }
  cout << endl;
  return 0;
}