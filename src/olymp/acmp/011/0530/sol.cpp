#include <bits/stdc++.h>

using namespace std;

char f(const string &s, char a, char b) {
  if (a == '0' && b == '0') {
    return s[0];
  }
  if (a == '0' && b == '1') {
    return s[1];
  }
  if (a == '1' && b == '0') {
    return s[2];
  }  
  return s[3];  
}

int main() {
  int w, h;
  cin >> w >> h;
  vector<string> a(h);
  for (int i = 0; i < h; ++i) {
    cin >> a[i];
  }
  vector<string> b(h);
  for (int i = 0; i < h; ++i) {
    cin >> b[i];
  }
  string s;
  cin >> s;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << f(s, a[i][j], b[i][j]);
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}