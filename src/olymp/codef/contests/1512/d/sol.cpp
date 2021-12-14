#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
using E = long long;
using Ve = vector<E>;

bool solve(Ve &a, Ve &b, int n, int m) {
  sort(begin(b), end(b), greater<E>());  
  
  E sum01 = 0LL;
  for (int i = 2; i < m; ++i) {
    sum01 += b[i];
  }

  if (b[1] == sum01) {
    for (int i = 2; i < m; ++i) {
      a[i - 2] = b[i];
    }
    return true;
  } else {
    E sum0 = sum01 + b[1];    
    int posx = -1;
    for (int i = 1; i < m; ++i) {
      if (sum0 - b[i] == b[0]) {
        posx = i; 
        break;
      }
    }
    if (posx >= 0) {      
      for (int i = 1, j = 0; i < m; ++i) {
       if (i != posx) {
         a[j] = b[i];
         ++j;
       }
      }
      return true;
    }
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int m = n + 2;
    Ve b(m);
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
    }
    Ve a(n);
    bool ok = solve(a, b, n, m);
    if (!ok) {
      cout << "-1";
    } else {
      copy(begin(a), end(a), ostream_iterator<int>(cout, " "));      
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}