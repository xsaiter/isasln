#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, vector<int> &a) {
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {    
    int l = 0, r = 0;
    for (int j = i + 1; j < n; ++j) {
      if (a[i] == a[j]) {
        continue;
      }      
      if (a[i] < a[j]) {        
        ++r;
      } else {
        ++l;
      }
    }
    b[i] = max(l, r);
  }
  return b;
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
    vector<int> b = solve(n, a);
    for (int i = 0; i < n; ++i) {
      cout << b[i] << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}