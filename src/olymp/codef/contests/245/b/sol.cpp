#include <bits/stdc++.h>

using namespace std;

string s;
ostringstream os;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s;
  int n = (int)s.size();
  int i;
  if (s[0] == 'f') {
    os << "ftp"; i = 3;
  } else {
    os << "http"; i = 4;
  }
  os << "://";
  int j = n - 1;
  while (true) {    
    if (s[j] == 'u' && s[j - 1] == 'r') break;
    --j;
  }
  for (int k = i; k < j - 1; ++ k) {
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