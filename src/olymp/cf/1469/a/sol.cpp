#include <bits/stdc++.h>

using namespace std;

bool solve(string &s) {    
  int n = (int)s.size();

  bool a = s[0] != ')';
  bool b = s[n - 1] != '(';
  
  int q = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') {
      ++q;
    }
  }     
  bool c = q % 2 == 0;

  return a && b && c; 
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << (solve(s) == true ? "YES" : "NO") << "\n";
  }
  cout << endl;
  return 0;
}