#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

bool solve(int n, int a, int b, int c, int d) {
  pii p = {(a - b) * n, (a + b) * n};
  pii q = {c - d, c + d};
  return (p.fi <= q.fi && p.se >= q.fi) || (p.fi >= q.fi && p.fi <= q.se);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;  
  while (t--) {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    cout << (solve(n, a, b, c, d) ? "Yes" : "No") << "\n";
  }
  cout << endl;
  return 0;
}