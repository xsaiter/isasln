#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;  
  cin >> s;
  int n = (int)s.size();
  ostringstream os;
  int i;
  if (s[0] == 'f') {
    os << "ftp"; i = 3;
  } else {
    os << "http"; i = 4;
  }
  os << "://";
  int j = n - 1;
  while (s[j] != 'u' || s[j - 1] != 'r') {    
    --j;
  }
  for (int k = i; k < j - 1; ++k) {
    os << s[k];
  }
  os << ".ru";
  if (j != n - 1) {
    os << "/";
    for (int k = j + 1; k < n; ++k) {
      os << s[k];
    }
  }
  cout << os.str() << endl;
  return 0;
}