#include <bits/stdc++.h>

using namespace std;

int main() {
  string a;
  getline(cin, a);
  vector<string> s(3);  
  getline(cin, s[0]);
  getline(cin, s[1]);
  getline(cin, s[2]);
  sort(begin(s), end(s));
  ostringstream oss;
  oss << a << ": " << s[0] << ", " << s[1] << ", " << s[2];
  cout << oss.str() << endl;
  return 0;
}