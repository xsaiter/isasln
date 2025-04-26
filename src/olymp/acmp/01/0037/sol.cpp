#include <bits/stdc++.h>

using namespace std;

const int M = 4;

bool solve(int n, double q, vector<vector<int>> &a) {
  return false;
}

int main() {  
  int n;
  double q;
  cin >> n >> q;
  vector<vector<int>> a(n, vector<int>(M));
  for (int i = 0; i <n ; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> a[i][j];
    }
  }
  cout << (solve(n, q, a) ? "Yes" : "No") << endl;
  return 0;              
}