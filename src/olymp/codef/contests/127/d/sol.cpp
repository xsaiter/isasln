#include <bits/stdc++.h>

using namespace std;

using T = long long;

T calc_hash(const string &str) { 
  return hash<string>{}(str);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = (int)s.size(); 

  int len = -1;
  for (int k = 1; k < n; ++k) {
    auto x = calc_hash(s.substr(0, k));
    auto y = calc_hash(s.substr(n - k, k));
    if (x == y) {                  
      for (int i = 1; i < n - k; ++i) {
        auto z = calc_hash(s.substr(i, k));
        if (z == x) {
          if (k > len) {
            len = k;
          }
          break;
        }
      }
    }
  }
  if (len == -1) {
    cout << "Just a legend";
  } else {
    cout << s.substr(0, len);
  }
  cout << endl;
  return 0;
}