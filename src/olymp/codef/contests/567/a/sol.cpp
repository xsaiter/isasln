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
    d[i] = d[i - 1] + abs(abs(x[i]) - abs(x[i - 1]));
  }
  for (int i = 0; i < n; ++i) {
    int mi = -1;
    if (i == 0) {
      mi = d[1];
    } else if (i == n - 1) {
      mi = d[n - 1];
    } else {
      mi = min(d[i + 1], d[i - 1]);
    }    
    int ma = -1;
    if (i == 0) {
      ma = d[n - 1];
    } else if (i == n - 1) {
      ma = d[0];
    } else {
      ma = max(d[0], d[n - 1]);
    }
    cout << mi << " " << ma << '\n';
  }
  cout << endl;
  return 0;
}