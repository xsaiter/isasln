#include <bits/stdc++.h>

using namespace std;
using V = vector<int>;

void solve(V &q, int n, V &mi, V &ma) {
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    V q(n);
    for (int i = 0; i < n; ++i) {
      cin >> q[i];
    }
    V mi; V ma;
    solve(q, n, mi, ma);
    copy(begin(mi), end(mi), ostream_iterator(cout, " "));
    cout << "\n";
    copy(begin(ma), end(ma), ostream_iterator(cout, " "));
  }
  cout << endl;
  return 0;
}