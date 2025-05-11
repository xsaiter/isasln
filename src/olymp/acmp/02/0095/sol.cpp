#include <bits/stdc++.h>

using namespace std;

int to_dig(char c) {
  return (int)c - (int)'0';
}

int calc(int x, int &n) {  
  if (x < 10) {
    return x;
  }  
  const string s = to_string(x);  
  x = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    x += to_dig(s[i]);
  }  
  ++n;
  return calc(x, n);
}

int main() {
  string s;
  cin >> s;
  int n = 0, x = 0;    
  int len = (int)s.size();
  for (int i = 0; i < len; ++i) {
    x += to_dig(s[i]);
  }
  if (len > 1) {
    n += 1;
  }
  int d = calc(x, n);
  cout << d << ' ' << n << endl;
  return 0;
}