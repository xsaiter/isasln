#include <bits/stdc++.h>

#define first fi
#define second se

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }    
  vector<int> x(n);
  for (int i = n - 1; i >= 0; --i) {        
    x[b[i]] = n - 1 - i;
  }
  int res = 0;
  for (int i = n - 1; i >= 0; --i) {    
    auto pos = x[a[i]];    
    for (int j = i - 1; j >= 0; --j) {
      if (x[a[j]] < pos) {
        ++res;
        break;
      }
    }
  }
  cout << res << endl;
  return 0;
}