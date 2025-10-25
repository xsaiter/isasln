#include <bits/stdc++.h>

using namespace std;

int ord(char c) {
  return (int)c - (int)'A';
}

bool solve(const string &a, const string &b) {  
  int n = (int)a.size();
  int m = (int)b.size();
  if (n != m) {
    return false;
  }
  vector<int> v(26);  
  for (int i = 0; i < n; ++i) {    
    v[ord(a[i])] += 1;
    v[ord(b[i])] -= 1;    
  }    
  for (auto x : v) {
    if (x != 0) {
      return false;
    }
  }    
  return true;
}

int main() {
  string a; cin >> a;
  string b; cin >> b;
  bool ans = solve(a, b);
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}