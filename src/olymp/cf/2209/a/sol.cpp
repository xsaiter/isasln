#include <bits/stdc++.h>

using namespace std;

using L = long long;

L solve(int n, L c, L k, vector<L> &a) {
  L cur = c;
  sort(a.begin(), a.end());  
  for (int i = 0; i < n; ++i) {
    if (a[i] > cur) {
      break;
    }    
    L diff = min(cur - a[i], k);
    k -= diff;
    cur += a[i] + diff;
  }
  return cur;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    L n, c, k;
    cin >> n >> c >> k;
    vector<L> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, c, k, a) << '\n';
  }
  cout << endl;
  return 0;
}