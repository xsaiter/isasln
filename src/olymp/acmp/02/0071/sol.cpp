#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a) {
  
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = solve(n, a);
  cout << ans << endl;
  return 0;
}