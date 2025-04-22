#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int solve(int n, vector<int> &a) {
  int res = 0;
  for (int i = 0; i < n; ++i) {
    
  }
  return res;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n; ++i) {
      cin >> a[i];
    }
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}