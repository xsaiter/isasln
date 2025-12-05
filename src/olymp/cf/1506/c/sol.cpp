#include <bits/stdc++.h>

using namespace std;

int solve(string &a, string &b) {
  int na = (int)a.size();
  int nb = (int)b.size();
  int res = INT_MAX;
  for (int i = 0; i < na; ++i) {
    for (int j = 0; j < nb; ++j) {
      int ii = i, jj = j;
      while (a[ii] == b[jj] && ii < na && jj < nb) {        
        ++ii; ++jj;
      }
      int cnt = i + (na - ii) + j + (nb - jj);
      res = min(res, cnt);
    }
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    cout << solve(a, b) << "\n";
  }
  cout << endl;
  return 0;
}
