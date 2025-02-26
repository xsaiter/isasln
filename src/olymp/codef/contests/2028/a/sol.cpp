#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int a, int b, string &s) {  
  int x = 0, y = 0;
  int K = 1 << 10;     

  for (int j = 0; j < K; ++j) {
    for (int i = 0; i < n; ++i) {
      if (x == a && y == b) {
        return true;
      }
      if (s[i] == 'N') {
        ++y;
      } else if (s[i] == 'E') {
        ++x;
      } else if (s[i] == 'S') {
        --y;
      } else if (s[i] == 'W') {
        --x;
      }      
    }        
  }

  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;    
    cout << (solve(n, a, b, s) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}