#include <bits/stdc++.h>

using namespace std;

string solve(int n, vector<int> &a) {    
  int x = 0, y = 0;
  int p = 0, q = n - 1;
  int j = 1;
  while (p <= q) {
    if (a[p] >= a[q]) {
      if (j % 2 == 1) {
        x += a[p];
      } else {
        y += a[p];
      }
      ++p;
    } else {
      if (j % 2 == 1) {
        x += a[q];
      } else {
        y += a[q];
      }
      --q;
    }
    ++j;
  }  
  ostringstream oss;
  oss << x << ":" << y;
  return oss.str();
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(n, a) << endl;
  return 0;
}