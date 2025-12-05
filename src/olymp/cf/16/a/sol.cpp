#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m; 
  cin >> n >> m;
  vector<string> ss(n);
  for (int i = 0; i < n; ++i) { cin >> ss[i]; }
  char a, b;  
  bool ok = true;
  for (int i = 0; i < n && ok; ++i) {
    a = ss[i][0];
    if (i > 0 && a == b) { ok = false; break; }
    b = a;
    for (int j = 1; j < m && ok; ++j) {      
      if (ss[i][j] != a) { ok = false; break; }
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}