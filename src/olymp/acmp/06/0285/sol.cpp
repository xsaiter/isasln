#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int m, vector<int>& a) {
  int mx = *max_element(a.begin(), a.end());
  if (mx > m) {
    return false;
  }
  if (mx == m) {
    return true;
  }
  int all = accumulate(a.begin(), a.end(), 0);
  if (all < m) {
    return false;
  }
  if (all == m) {
    return true;
  }
  vector<int> b;
  bool ans = false;
  function<void(int)> Gen = [&](int k) {
    if (k == n + 1) {
      int sum = 0;
      for (const auto& x : b) {
        sum += a[x - 1];
      }
      if (sum == m && (all - m) <= m) {
        ans = true;
      }
    } else {
      b.push_back(k);
      Gen(k + 1);
      b.pop_back();
      Gen(k + 1);
    }
    };
  Gen(1);
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << (solve(n, m, a) ? "yes" : "no") << endl;
  return 0;
}