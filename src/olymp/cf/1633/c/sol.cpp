#include <bits/stdc++.h>

using namespace std;
using L = long long;

L cnt(const L &h, const L &d) {
  if (h <= d) return 1;
  L x = h % d;
  L n;
  if (x == 0) n = h / d; 
  else n = (h - x) / d + 1;
  return n;
}

bool can(const L &hc, const L &dc, const L &hm, const L &dm) {  
  L nc = cnt(hc, dm);
  L nm = cnt(hm, dc);
  return nc >= nm;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    L hc, dc, hm, dm;
    cin >> hc >> dc;
    cin >> hm >> dm;
    L k, w, a;
    cin >> k >> w >> a;
    bool ans = false;
    for (L i = 0; i <= k; ++i) {
      ans = can(hc + i * a, dc + (k - i) * w, hm, dm);
      if (ans) break;
    }
    cout << (ans == true ? "YES" : "NO") << "\n";
  }
  cout << endl;
  return 0;
}