#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int solve(int n, int m, vector<string>& a) {
  int d = INF;
  for (int i = 0; i < n; ++i) {
    int a_end = -1, b_beg = -1;
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 'A') {
        a_end = j;
      } else if (a[i][j] == 'B') {
        b_beg = j;
        break;
      }
    }
    if (a_end != -1 && b_beg != -1) {      
      d = min(d, b_beg - a_end - 1);
    }
  }
  return d == 1e9 ? 0 : d;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(n, m, a) << endl;
  return 0;
}