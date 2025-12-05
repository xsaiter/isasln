#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = (int)s.size();
  int res = 0;  
  vector<int> a(n, 0);
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == 'V' && s[i + 1] == 'K') {
      ++res; a[i] = 1; a[i + 1] = 1;
    } 
  }
  for (int i = 0; i < n - 1; ++i) {
     bool c = s[i] == 'K' && s[i + 1] == 'V';
     if (!c && a[i] == 0 && a[i + 1] == 0) {
       ++res; break;
     }
  }  
  cout << res << endl;
  return 0;
}