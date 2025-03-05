#include <bits/stdc++.h>

using namespace std;

void solve(int n, const vector<int> &p, const string &s, vector<int> &f) {  
  vector<int> g(n, 0);
  vector<int> k(n, -1);  
  vector<int> visited(n, 0);
  int nc = 0;
  for (int i = 0; i < n; ++i) {
    if (k[i] != -1) {
      f[i] = g[k[i]];      
      continue;
    }
    int j = i;    
    while (visited[j] != 1) {      
      k[j] = nc;    
      if (s[j] == '0') {        
        ++g[nc];
      }
      visited[j] = 1;
      j = p[j] - 1;      
    }    
    ++nc;
    if (k[i] != -1) {
      f[i] = g[k[i]];
    }
  }    
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    string s;
    cin >> s;
    vector<int> f(n, 0);
    solve(n, p, s, f);
    for (int i = 0; i < n; ++i) {
      cout << f[i] << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}