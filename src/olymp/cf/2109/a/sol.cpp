#include <bits/stdc++.h>

using namespace std;

bool solve(int n, const vector<int> &a) {    
  bool z = false;
  if (a[0] == 0) { 
    z = true;
  }
  for (int i = 1; i < n; ++i) {   
    if (a[i - 1] == 0 && a[i] == 0) {      
      return true;
    }
    if (a[i] == 0) {
      z = true;
    }
  }
  if (z == 0) {
    return true;
  }
  return false;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << (solve(n, a) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}

