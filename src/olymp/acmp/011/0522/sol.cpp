#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }  
  set<int> aa;
  for (int i = 0; i < n; ++i) {
    aa.insert(a[i]);
  }
  set<int> bb;
  for (int i = 0; i < m; ++i) {
    bb.insert(b[i]);
  }
  int ans = 0;  
  if (aa == bb) {
    ans = 1;
  }
  cout << ans << endl;
  return 0;
}