#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &b) {    
  set<int> ss(begin(b), end(b));
  vector<int> a(begin(ss), end(ss));
  sort(begin(a), end(a));
  n = (int)a.size();
  int ans = 0;  
  int cur = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] > a[i - 1]) {
      cur += 1;
    } else {
      ans = max(ans, cur);
      cur = 1;
    }
  }
  ans= max(ans, cur);
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    cout << solve(n, b) << '\n';
  }
  cout << endl;
  return 0;
}