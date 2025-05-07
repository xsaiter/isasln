#include <bits/stdc++.h>

using namespace std;

int mi(int n, int m) {    
  return n + max(m - n, 0);
}

int ma(int n, int m) {
  if (m == 0) {
    return n;
  }
  return m + n - 1;
}

int main() {
  int n, m;
  cin >> n >> m;
  if (n == 0 && m == 0) {
    cout << 0 << ' ' << 0;
  } else if (n == 0) {
    cout << "Impossible";
  } else {
    cout << mi(n, m) << ' ' << ma(n, m);
  }  
  cout << endl;
  return 0;
}