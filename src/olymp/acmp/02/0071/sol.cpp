#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int sum(const vector<int> &a, int l, int r) {
  int ans = 0;
  for (int i = l; i <= r; ++i) {
    ans += a[i];
  }
  return ans;
}

int solve(int n, const vector<int> &a, int l, int r) {
  int best = INF;
  sort(a.begin(), e.end());
  for (int p = 1; p < n - 1; ++p) {    
    for (int q = 0; q < n; ++q) {

    }
  }
  return best;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }  
  sort(a.begin(), a.end());
  cout << solve(n, a, 0, n - 1) << endl;
  return 0;
}