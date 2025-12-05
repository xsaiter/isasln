#include <bits/stdc++.h>

using namespace std;

using L = long long;

L cnt(L i, L j, L n, L m, L k) {
  L x = min(i, n - k) - max((L)-1, i - k);
  L y = min(j, m - k) - max((L)-1, j - k);
  return x * y;
}

L solve(L n, L m, L k, L w, vector<L> &a) {  
  sort(begin(a), end(a), greater<>());
  L N = n * m;
  vector<L> b(N, 0L);  
  for (L i = 0; i < n; ++i) {
    for (L j = 0; j < m; ++j) {
      b[i + j] = cnt(i + 1, j + 1, n, m, k);
    }
  }  
  sort(begin(b), end(b), greater<>());
  L res = 0L;
  L nn = min(N, w);
  for (L i = 0; i < nn; ++i) {
    res += b[i] * a[i];
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    L n, m, k;
    cin >> n >> m >> k;
    L w;
    cin >> w;
    vector<L> a(w);
    for (int i = 0; i < w; ++i) {
      cin >> a[i];
    }
    cout << solve(n, m, k, w, a) << '\n';
  }
  cout << endl;
  return 0;
}