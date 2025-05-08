#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &a) {
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
    }  
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << solve(n, a) << endl;
  return 0;
}