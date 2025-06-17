#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int m, const vector<vector<int>> &a) {
  int c = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (
        a[i][j] == c && 
        a[i + 1][j] == c && 
        a[i][j + 1] == c && 
        a[i + 1][j + 1] == c) {
          return true;
       }
    }
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {            
      if (s[j] == '*') {
        a[i][j] = 1;
      }
    }
  }
  cout << (solve(n, m, a) ? "SQUARE" : "CIRCLE") << endl;
  return 0;
}