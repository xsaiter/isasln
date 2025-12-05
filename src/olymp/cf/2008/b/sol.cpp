#include <bits/stdc++.h>

using namespace std;

bool is_edge(int k, int j) {      
  int x = j % k;
  if (x == 0) {
    x = k;
  }
  int y = 1 + (j - x) / k;  
  return x == 1 || x == k 
    || y == 1 || y == k;  
}

bool solve(int n, const string &s) {
  int k = (int)sqrt(n);
  if (k * k != n) {
    return false;
  }  
  for (int i = 0; i < n; ++i) {    
    if (is_edge(k, i + 1)) {
      if (s[i] == '0') {
        return false;
      }
    } else {
      if (s[i] == '1') {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << (solve(n, s) ? "Yes" : "No") << '\n';
  }
  cout << endl;
  return 0;
}