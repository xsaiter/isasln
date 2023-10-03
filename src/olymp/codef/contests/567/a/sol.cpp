#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  vector<int> d(n);
  d[0] = 0;
  for (int i = 1; i < n; ++i) {    
    int len = 0;
    if (x[i - 1] < 0) {
      if (x[i] < 0) {
        len = abs(x[i - 1]) - abs(x[i]);
      } else {
        len = abs(x[i - 1]) + x[i];
      }
    } else {
      len = x[i] - x[i - 1];
    }
    d[i] = d[i - 1] + len;
  }
  for (int i = 0; i < n; ++i) {
    int mi = -1;
    if (i == 0) {
      mi = d[1];
    } else if (i == n - 1) {
      mi = d[n - 1] - d[n - 2];
    } else {
      mi = min(d[i + 1] - d[i], d[i] - d[i - 1]);
    }    
    int ma = -1;
    if (i == 0) {
      ma = d[n - 1];
    } else if (i == n - 1) {
      ma = d[n -1];
    } else {
      ma = max(d[i] - d[0], d[n - 1] - d[i]);
    }
    cout << mi << " " << ma << '\n';
  }
  cout << endl;
  return 0;
}