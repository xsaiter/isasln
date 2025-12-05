#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a = 0, b = 0;
    int k = 0;
    ostringstream oss;
    while (true) {
      if (a == 0) a = 1;
      else if (a == 1) a = 2;
      else if (a == 2) a = 3;
      else if (a == 3) a = 4;
      else if (a == 4) a = 6;
      else if (a == 6) a = 12;
      else { break; }
      b = 12 / a;      
      for (int i = 0; i < b; ++i) {        
        bool all_x = true;
        for (int j = 0; j < a; ++j) {
          if (s[i + j * b] != 'X') {
            all_x = false; 
            break;
          }
        }
        if (all_x) {
          oss << a << "x" << b << " ";
          ++k;
          break;
        }
      }      
    }    
    cout << k << " " << oss.str();
    cout << "\n";
  }
  cout << endl;
  return 0;
}