#include <bits/stdc++.h>

using namespace std;

bool solve(int n, vector<int> &a) {  
  int x1 = 0, x2 = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      ++x1;
    } else {
      ++x2;
    }    
  }
  if (x1 == 0 && x2 == 0) {
    return true;
  }
  if (x1 == 0) {
    return x2 % 2 == 0;
  }
  if (x2 == 0) {
    return x1 % 2 == 0;
  }
  if (x1 % 2 == 0 && x2 % 2 == 0) {
    return true;
  }
  if (x2 % 2 != 0) {
     return x1 > 1 && x1 % 2 == 0;
  }
  return x1 % 2 == 0;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << (solve(n, a) == true ? "YES" : "NO") <<  "\n";
  }
  cout << endl;
  return 0;
}