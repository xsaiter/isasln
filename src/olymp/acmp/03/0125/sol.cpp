#include <bits/stdc++.h>

using namespace std;

int solve(int n, const vector<vector<int>> &a, const vector<int> &c) {
  int ans = 0;  
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (a[i][j] == 1 && i != j) {
        if (c[i] != c[j]) {
          ans += 1;          
        }
      }
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }  
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];    
  }
  cout << solve(n, a, c) << endl;
  return 0;
}