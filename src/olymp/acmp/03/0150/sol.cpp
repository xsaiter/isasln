#include <bits/stdc++.h>

using namespace std;
using M = vector<vector<int>>;

void dfs(int n, int s, const M &a, set<int> &acc, vector<bool> &vis) {
  if (vis[s]) {
    return;
  }
  vis[s] = true;
  acc.insert(s);
  for (int j = 0; j < n; ++j) {    
    if (a[s][j]== 1) {
      dfs(n, j, a, acc, vis);
    }
  }
}

int solve(int n, int s, const M &a) {  
  set<int> acc;
  vector<bool> vis(n, false);
  dfs(n, s, a, acc, vis);
  return (int)acc.size() - 1;
}

int main() {
  int n, s;
  cin >> n >> s;
  --s;
  M a(n, vector<int>(n));
  for(int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  cout << solve(n, s, a) << endl;
  return 0;
}