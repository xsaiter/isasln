#include <bits/stdc++.h>

using namespace std;

const int M = 40;

bool is_dig(char c) {  
  return isdigit(c);
}

int rep(string &s) {
  if (s.empty()) {
    return 1;
  }
  return atoi(s.c_str());
}

int main() {
  string s;
  cin >> s;
  int n = (int)s.size();
  string t;
  int m = 0;
  for (int i = 0; i < n; ++i) {    
    if (is_dig(s[i])) {
      t += s[i];
    } else {
      int k = rep(t); t.clear();
      for (int j = 0; j < k; ++j) {        
        if (m >= M) {
          cout << '\n';
          m = 0;
        }
        cout << s[i];
        m += 1;
      }
    }
  }
  cout << endl;
  return 0;
}