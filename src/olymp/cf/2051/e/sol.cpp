#include <bits/stdc++.h>

using namespace std;

using L = long long;

L solve(int n, int k, vector<L> &a, vector<L> &b) {  
  set<L> sa, sb;  
  for (int i = 0; i < n; ++i) {    
    sa.insert(a[i]);
    sb.insert(b[i]);
  }
  vector<L> c(2 * n);
  for (int i = 0; i < n; ++i) {
    c[2 * i] = a[i];
    c[2 * i + 1] = b[i];
  }
  L ans = 0LL;        
  for (int i = 0; i < 2 * n; ++i) {    
    auto it = sb.lower_bound(c[i]);
    int nb = distance(sb.begin(), it);
    it = sa.lower_bound(c[i]);
    int na = n - distance(sa.begin(), it);    
    int cnt = nb - na;
    if (k >= cnt) {
      ans = max(ans, c[i] * nb);
    }    
  }  
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<L> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<L> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    cout << solve(n, k, a, b) << '\n';
  }
  cout << endl;
  return 0;
}