#include <bits/stdc++.h>

using namespace std;

struct Res {
  string s;
  bool yes;
};

// abbc -> abc
// abababab -> ababab ababab
               //ababab
// 1 2 1 3 2 1 3

Res solve(string &t) {
  Res no = { .yes = false };  
  int n = (int)t.size();
  int K = n / 2;
  for (int k = 1; k < K; ++k) {
    for (int i = k; i < n; ++i) {
      if (t[i] == t[j]) {        
      }
    }    
  }
  return no;
}

int main() {
  string t;
  cin >> t;  
  Res res = solve(t);
  if (res.yes) {
    cout << "YES" << '\n';
    cout << res.s << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}