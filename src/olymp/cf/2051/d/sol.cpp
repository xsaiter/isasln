#include <bits/stdc++.h>

using namespace std;

using L = long long;

L solve(int n, L x, L y, vector<L> &a) {  
  L s = accumulate(a.begin(), a.end(), 0LL);
  sort(a.begin(), a.end());
  L ans = 0LL;
  int j = n - 1;
  for (int i = 0; i < n; ++i) {    
    while (i < j && a[i] + a[j] > s - x) {
      --j;
    }
    if (i < j) {
      ans += j - i;
    }
  }
  j = n - 1;
  for (int i = 0; i < n; ++i) {    
    while (i < j && a[i] + a[j] >= s - y) {
      --j;
    }
    if (i < j) {
      ans -= j - i;
    }
  }  
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    L x, y;
    cin >> n >> x >> y;
    vector<L> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, x, y, a) << '\n';
  }
  cout << endl;
  return 0;
}