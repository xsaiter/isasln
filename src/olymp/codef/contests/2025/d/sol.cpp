#include <bits/stdc++.h>

using namespace std;

using Matrix = vector<vector<int>>;

// 0 1 0 2 0 -3 0 -4 0 -5
// d[i][I] - answer after processing i-records while value of I is I => S = P - I
// d[i][I] = max(d[i - 1][I - 1], d[i - 1][I])

int solve(int n, int m, vector<int> &r) {
  int res = 0;  
  vector<vector<int>> d;
  int I = 0, S = 0;
  int dn = 0, dm = 0;
  for (int i = 0; i < dn; ++i) {    
    for (int j = 0; j < dm; ++j) {
      
    }
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }
  return 0;
}