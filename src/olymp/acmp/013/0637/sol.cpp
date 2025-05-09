#include <bits/stdc++.h>

using namespace std;

int solve(int n, const vector<int> &a, int k) {  
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += min(a[i], k);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int k;
  cin >> k;
  cout << solve(n, a, k) << endl;
  return 0;
}