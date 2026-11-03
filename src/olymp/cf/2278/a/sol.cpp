#include <bits/stdc++.h>

using namespace std;

const int K = 26;

int ord(char c) {
  return (int)c - (int)'a';
}

bool solve(int n, int m, string &p, string &q) {  
  vector<int> a(K), b(K);  
  for (int i = 0; i < n; ++i) {    
    a[ord(p[i])] += 1;
  }  
  for (int i = 0; i < m; ++i) {
    b[ord(q[i])] += 1;
  }
  for (int i = 0; i < K; ++i) {
    if (b[i] > 0) {
      a[i] -= b[i];
    }
  }
  int ps = ord('s'), pi = ord('i'), px = ord('x');
  for (int i = 0; i < K; ++i) {      
    if (i == ps || i == pi || i == px) {
      if (a[i] != 1) {
        return false;
      }
    } else {
      if (a[i] != 0) {
        return false;
      }
    }
  }  
  return true;  
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    string p, q;
    cin >> p >> q;
    cout << (solve(n, m, p, q) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}