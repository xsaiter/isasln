#include <bits/stdc++.h>

using namespace std;

using A = vector<vector<vector<char>>>;

int path(int nb, const vector<vector<int>> &b, int x, int y) {
  queue<int> q;
  vector<bool> vi(nb);
  vector<int> di(nb);
  vi[x] = true;
  di[x] = 0;
  q.push(x);
  while (!q.empty()) {
    int s = q.front(); q.pop();
    for (auto u : b[s]) {
      if (vi[u]) {
        continue;
      }
      vi[u] = true;
      di[u] = di[s] + 1;
      q.push(u);
    }
  }
  return di[y];
}

int solve(const A &a, int h, int m, int n) {
  int nb = h * m * n;  
  vector<vector<int>> b(nb, vector<int>());
  int x = -1, y = -1;
  for (int k = 0; k < h; ++k) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        char ch = a[k][i][j];
        if (ch == 'o') {
          continue;
        }
        int base_c = k * n * m;
        int c = base_c + i * n + j;        
        if (ch == '1') {
          x = c;
        } else if (ch == '2') {
          y = c;
        }
        if (i + 1 < m && a[k][i + 1][j] != 'o') {          
          int cc = base_c + (i + 1) * n + j;
          b[c].push_back(cc);
          b[cc].push_back(c);          
        }
        if (j + 1 < n && a[k][i][j + 1] != 'o') {          
          int cc = base_c + i * n + j + 1;
          b[c].push_back(cc);
          b[cc].push_back(c);          
        }
        if (k != h - 1) {
          int cc = (k + 1) * n * m + i * n + j;
          b[c].push_back(cc);
        }
      }
    }
  }
  return path(nb, b, x, y) * 5;
}

int main() {  
  int h, m, n;    
  cin >> h >> m >> n;
  A a(h, vector<vector<char>>(m, vector<char>(n)));  
  for (int k = 0; k < h; ++k) {    
    for (int i = 0; i < m; ++i) {
      string s; cin >> s;
      for (int j = 0; j < n; ++j) {        
        a[k][i][j] = s[j];
      }
    }
  }  
  cout << solve(a, h, m, n) << endl;
  return 0;
}