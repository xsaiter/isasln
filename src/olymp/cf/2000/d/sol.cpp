#include <bits/stdc++.h>

using namespace std;
using L = long long;

L sum_range(const vector<L> &d, int l, int r) {
  if (l == 0L) {
    return d[r];
  }  
  return d[r] - d[l - 1];
}

vector<L> diff(const vector<int> &a, int n) {
  vector<L> d(n);
  d[0] = a[0];
  for (int i = 1; i < n; ++i) {
    d[i] = d[i - 1] + (L)a[i];
  }
  return d;
}

L solve(int n, const vector<int> &a, const string &s) {    
  vector<L> d = diff(a, n);
  L res = 0L;
  int l = 0, r = n - 1;
  while (l <= n - 1 && r >= 0 && l < r) {
    if (s[l] == 'L') {
      while (l < r) {
        if (s[r] == 'R') {
          res += sum_range(d, l, r);
          --r;
          break;
        }
        --r;
      }
    }
    ++l;
  }
  return res;
}

int main() {  
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    string s;
    cin >> s;
    cout << solve(n, a, s) << '\n';
  }
  cout << endl;
  return 0;
}
