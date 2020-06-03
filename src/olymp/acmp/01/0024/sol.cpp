#include <bits/stdc++.h>

using namespace std;

using R = long long;

R calc(int n, int m) {  
  if (n < m) {
    return 0;
  }
  if (m == 0) {
    return 1;
  }
  if (m == 1) {
    return n;
  }  
  R res = 0;
  for (int k = 1; k <= n; ++k) {
    for (int j = 1; j <= n; ++j) {
      int i = j;
      R t = 0;
      while (i <= n) {
        i += k;
        ++t;
        if (t == m) {
          ++res;
          break;
        }
      }            
    }    
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;  
  cout << calc(n, m) << endl;
  return 0;
}