#include <bits/stdc++.h>

using namespace std;

int di(char c) {
  if (c == 'A' || c == 'a') {
    return 10;
  }
  if (c == 'B' || c == 'b') {
    return 11;
  }
  return (int)c - (int)'0';
}

int get_sys(int n) {
  if (n == 100) {
    return 12;
  }
  return (n % 10) + 2;    
}

string solve(int n, const string &k) {
  int m = get_sys(n);  
  if (m == 10) {
    return k;
  }
  int len = (int)k.size();
  int res = 0;
  for (int i = 0; i < len; ++i) {
    int d = di(k[i]);
    res += d * pow(m, len - i - 1);    
  }
  return to_string(res);
}

int main() {
  int n;  
  cin >> n;
  string k;
  cin >> k;
  cout << solve(n, k) << endl;
  return 0;
}