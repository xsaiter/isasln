#include <bits/stdc++.h>

using namespace std;

using Matrix = vector<vector<int>>;

// 0 1 0 2 0 -3 0 -4 0 -5
// d[i][I] - answer after processing i-records while value of I is I => S = P - I
// d[i][I] = max(d[i - 1][I - 1], d[i - 1][I])

int solve(int n, int m, vector<int> &r) {
  int res = 0;  
  vector<vector<int>> d(n);
  int I = 0, S = 0;    
  for (int i = 0; i < n; ++i) {
    auto elm = find(begin(d), end(d), i);
    auto v = *elm;
    if (v.exists(0)) {
      
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