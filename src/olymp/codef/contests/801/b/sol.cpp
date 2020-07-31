#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string x, y;
  cin >> x >> y;
  int n = (int)x.size();
  vector<char> z(n);
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    if (x[i] == y[i]) {
      z[i] = x[i];
    } else if (x[i] > y[i]) {
      z[i] = y[i];
    } else {
      ok = false;
      break;
    }
  }
  if (ok) {    
    copy(begin(z), end(z), ostream_iterator<char>(cout, ""));
  } else {
    cout << -1;
  }
  cout << endl;
  return 0;
}