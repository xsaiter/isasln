#include <bits/stdc++.h>

using namespace std;
using L = long long;

int cnt(L h, L d) {
  if (d >= h) return 1;
  L x = h % d;
  L n;
  if (x == 0) n = h / d; 
  else n = (h - x) / d  + 1;
  return n;
}

bool can(L hc, L dc, L hm, L dm) {  
  L nc = cnt(hc, dm);
  L nm = cnt(hm, dc);
  if (nc >= nm) return true;
  return false;
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
    for (int i = 0; i < k; ++i) {
      ans = can(hc + i, dc + k - i, hm, dm);
      if (ans) break;
    }
    cout << (ans == true ? "YES" : "NO") << "\n";
  }
  cout << endl;
  return 0;
}