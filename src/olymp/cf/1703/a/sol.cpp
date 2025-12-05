#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;    
    bool ok = tolower(s[0]) == 'y' && tolower(s[1]) == 'e' && tolower(s[2]) == 's';
    cout << (ok ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}