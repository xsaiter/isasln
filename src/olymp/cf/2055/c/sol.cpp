#include <bits/stdc++.h>

using namespace std;

using L = long long;

void solve(int n, int m, const string &s, vector<vector<L>> &a) {  
  int k = (int)s.size();  
  int ci = 0, cj = 0;  
  L sum;
  for (int i = 0; i < k; ++i) {    
    sum = 0LL;
    if (s[i] == 'R') {
      for (int ii = 0; ii < n; ++ii) {        
        sum += a[ii][cj];        
      }
      a[ci][cj] = sum * (-1LL);       
      cj++;      
    } else {            
      for (int jj = 0; jj < m; ++jj) {        
        sum += a[ci][jj];        
      }      
      a[ci][cj] = sum * (-1LL);       
      ci++;
    }    
  }
  sum = 0LL;
  for (int i = 0; i < n; ++i) {
    sum += a[i][m - 1];    
  }  
  a[n - 1][m - 1] = sum * (-1LL);
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<L>> a(n, vector<L>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }
    solve(n, m, s, a);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << a[i][j] << ' ';
      }
      cout << '\n';
    }
  }
  cout << endl;
  return 0;
}