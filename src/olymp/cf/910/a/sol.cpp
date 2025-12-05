#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, d;
  cin >> n >> d;
  string s;
  cin >> s;
  int res = 0;  
  int p = d;
  int i = 0;
  bool ok = false;
  while (p) {
    int j = i + p;
    if (j < n && s[j] == '1') {             
      ++res;
      if (j == n - 1) {        
        ok = true;
        break;
      }
      i = j;
      p = d;
    } else {
      --p;
    }    
  }
  cout << (ok ? res : -1) << endl;
  return 0;
}