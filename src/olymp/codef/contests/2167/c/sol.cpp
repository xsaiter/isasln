#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, vector<int> &a) {  
  int p = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      ++p;
    }  
  }
  if (0 < p && p < n) {
    sort(begin(a), end(a));
  }
  return a;  
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