#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int mi = INF;
  int mx = -INF;
  for (int i = 0; i < n; ++i) {
    if (mi > a[i]) {
      mi = a[i];
    }
    if (mx < a[i]) {
      mx = a[i];
    }
  }
  cout << mi << " " << mx << endl;
  return 0;
}