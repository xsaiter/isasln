#include <bits/stdc++.h>

using namespace std;

using C = long long;

// 0 < i <= len(a) and a[i] = len(a) + 1 - i
// add (i - 1) zeros to the the end of array

C dp(int n, vector<C> &a, C k, map<C, C> &m) {    
  if (m.count(k)) {
    return m[k];
  }
  auto best = k;
  for (int i = 0; i < n; ++i) {    
    auto j = i + 1;
    if (a[i] == k + 1 - j && j - 1 > 0) {      
      C res = dp(n, a, k + j - 1, m);      
      best = max(best, res);      
    }    
  }  
  m.insert(pair<C, C>(k, best));
  return best;
}

C solve(int n, vector<C> &a) {  
  map<C, C> m;
  return dp(n, a, n, m);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<C> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, a) << '\n';        
  }
  cout << endl;
  return 0;
}