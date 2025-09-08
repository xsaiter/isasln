#include <bits/stdc++.h>

using namespace std;

int seek(const vector<int> &a, int n, int p, int q, int d, vector<int> &vis) {    
  int j = (p + q) / 2;
  return j;
}

int solve(int n, int d, vector<int> &m) {      
  int ans = 0;
  vector<int> a;
  for (int i = 0; i < n; ++i) {
    if (m[i] >= d) {
      ans += 1;
    } else {
      a.push_back(m[i]);
    }
  }  
  sort(begin(a), end(a));
  n = (int)a.size();
  vector<int> vis(n, 0);  
  for (int i = 0; i < n - 1; ++i) {
    if (vis[i] == 1) {
      continue;
    }
    int j = seek(a, n, i + 1, n, d, vis);
    vis[j] = 1;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, d;
  cin >> n >> d;
  vector<int> m(n);
  for (int i = 0 ; i < n; ++i) {
    cin >> m[i];
  }
  cout << solve(n, d, m) << endl;
  return 0;
}