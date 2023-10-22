#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> p[i];
  }
  int res = 0;
  int c = INT_MAX;
  for (int i = 0; i < n; ++i) {    
    c = min(c, p[i]);
    res += a[i] * c;
  }  
  cout << res << endl;
  return 0;
}