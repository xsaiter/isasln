#include <bits/stdc++.h>

using namespace std;

using L = long long;

L solve(int n, int k, vector<L> &a, vector<L> &b) {
  L ans = 0LL;
        
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
        
  vector<L> c = a;
  c.insert(c.end(), b.begin(), b.end());
        
  for (int x : c) {
    int nb = n - (lower_bound(b.begin(), b.end(), x) - b.begin());
    int na = n - (lower_bound(a.begin(), a.end(), x) - a.begin());      
    int cnt = nb - na;        
    if (cnt <= k) {
      ans = max(ans, (L)x * nb);
    }
  }    
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
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