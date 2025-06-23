#include <bits/stdc++.h>

using namespace std;

int md(int k) {
  if (k == 1) {
    return 1;
  }
  if (k % 2 == 0) {
    return  k / 2 + 1;
  }
  return (k + 1) / 2;
}

int solve(int k, vector<int> &a) {  
  sort(begin(a), end(a));
  int ans = 0;  
  int m = md(k);
  for (int i = 0; i < m; ++i) {
    ans += md(a[i]);
  }
  return ans;
}

int main() {
  int k;
  cin >> k;  
  vector<int> a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }
  cout << solve(k, a) << endl;
  return 0;
}