#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<int> load_dp(int n, const vector<int>& a, int s) {
  vector<int> dp(s + 1);
  for (int x = 1; x <= s; ++x) {
    dp[x] = INF;
    for (int i = 0; i < n; ++i) {
      int k = x - a[i];
      if (k >= 0) {
        dp[x] = min(dp[x], dp[k] + 1);
      }
    }
  }
  return dp;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int k;
  cin >> k;
  vector<int> b(k);
  for (int i = 0; i < k; ++i) {
    cin >> b[i];
  }
  int mx = *max_element(begin(b), end(b));
  vector<int> dp = load_dp(n, a, mx);
  for (int i = 0; i < k; ++i) {
    int ans = dp[b[i]];
    if (ans == INF || ans <= 0) {
      cout << 0;
    } else {
      cout << 1;
    }
    cout << ' ';
  }
  cout << endl;
  return 0;
}