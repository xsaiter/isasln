#include <bits/stdc++.h>

using namespace std;

bool is_letter(char c) {
  return c == 'A' || c == 'B' || c == 'C'
    || c == 'E' || c == 'H' || c == 'K'
    || c == 'M' || c == 'O' || c == 'P'
    || c == 'T' || c == 'X' || c == 'Y';
}

bool is_dig(char c) {
  return isdigit(c);
}

bool solve(const string &s) {
  int n = (int)s.size();
  if (n != 6) {
    return false;
  }
  return is_letter(s[0]) 
    && is_dig(s[1]) 
    && is_dig(s[2])
    && is_dig(s[3])
    && is_letter(s[4])
    && is_letter(s[5]);    
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    cout << (solve(s) ? "Yes" : "No") << '\n';
  }
  cout << endl;
  return 0;
}