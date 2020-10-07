#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, int n) {
  int res = 0;
  if (n == 0) return 0;
  sort(begin(a), end(a));
  int x = 0, y = 0;
  bool fx = false, fy = false;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      if (!fx) {
        if (a[i] - x <= 1) {
          x = a[i];
        } else {
          ++x;
          fx = true;
        }
      }      
    } else {
      if (!fy) {
        if (a[i] - y <= 1) {
          y = a[i];
        } else {
          ++y;
          fy = true;
        }
      }
    }    
  }
  if (!fx) ++x;
  if (!fy) ++y;
  res = x + y;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(a, n) << "\n";
  }
  cout << endl;
  return 0;
}