#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int solve(int n, const vector<vector<int>> &a) {
  int best = INF;  
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {      
      for (int j = 0; j < n; ++j) {                        
        if (k != i && i != j && j != k) {
          int cur = a[k][i] + a[i][j] + a[j][k];
          best = min(best, cur);
        }        
      }      
    }
  }
  return best;
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
  cout << solve(n, a) << endl;
  return 0;
}