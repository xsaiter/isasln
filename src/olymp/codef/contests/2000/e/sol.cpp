#include <bits/stdc++.h>

using namespace std;

using L = long long;
using M = vector<vector<int>>;

L spect(int w, const vector<int> &a) {
  L res = 0L;
  return res;
}

L count_sq(int n, int k) {  
  if (n < k) {
    return 0;
  }
  if (n == k) {
    return 1;
  }
  L d = (L)(n - k);
  return d * d;  
}

int center(int x) {
  int rem = x % 2;
  if (rem == 0) {
    return x / 2;
  }
  return (x + 1) / 2;
}

L solve(int n, int m, int k, int w, vector<int> &a) {
  sort(begin(a), end(a), greater<>());
  L res = 0L;
  int W = n * m;
  M d(n, vector<int>(m, 0));
  int cn = center(n), cm = center(m);    
  int i = 0;
  while (i < w) {        
    d[cn][cm] = a[i];
    if (cn < cm) {      
    }
    ++i;    
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vector<int> a(w);
    for (int i = 0; i < w; ++i) {
      cin >> a[i];
    }
    cout << solve(n, m, k, w, a) << '\n';
  }
  cout << endl;
  return 0;
}
// 4 + 4 + 4 + 3 + 3 + 2