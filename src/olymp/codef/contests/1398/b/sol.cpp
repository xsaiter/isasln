#include <bits/stdc++.h>

using namespace std;

int solve(string &s) {
  int n = (int)s.size();
  vector<int> a;
  int len = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {            
      ++len;
    } else {      
      if (len > 0) a.push_back(len);
      len = 0;      
    }
  }
  if (len > 0) a.push_back(len);
  
  sort(begin(a), end(a), greater<int>());
  
  int res = 0;
  int m = (int)a.size();
  for (int i = 0; i < m; ++i) {
    if (i % 2 == 0) {
      res += a[i];
    }    
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << solve(s) << "\n";
  }
  cout << endl;
  return 0;
}