#include <bits/stdc++.h>

using namespace std;

int solve(int n, const vector<int> &a) {
  int ans = 0;    
  for (int i = 0; i < n; ++i) {
    if (a[i] <= i + 1) {
      ans++;
    }
  }
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i]; 
    }
    cout << solve(n, a) << '\n';
  }
  cout << endl;
  return 0;
}