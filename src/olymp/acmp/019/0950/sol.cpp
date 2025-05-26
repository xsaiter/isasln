#include <bits/stdc++.h>

using namespace std;

const int N = 26;

int main() {
  string s;
  cin >> s;
  int n = (int)s.size();
  vector<string> a(N);
  vector<char> sym(N);  
  for (int i = 0; i < N; ++i) {
    sym[i] = (char)('a' + i);
    ostringstream tmp;
    for (int j = 0; j < i; ++j) {      
      tmp << '0';
    }
    tmp << '1';
    a[i] = tmp.str();
  }  
  ostringstream oss;
  int pos = 0;  
  while (pos < n) {    
    for (int j = N - 1; j >= 0; --j) {
      int len = j + 1;
      if (len <= n - pos) {        
        if (s.substr(pos, len) == a[j]) {
          oss << sym[j];
          pos += len;
          break;
        }
      }
    }    
  }
  cout << oss.str() << endl;
  return 0;
}