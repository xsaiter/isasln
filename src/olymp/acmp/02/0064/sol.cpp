#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int len(int x) {
  int r = 1;
  while (x > 9) {
    int rem = x % 10;
    x = (x - rem) / 10;
    ++r;
  }
  return r;
}

int to_dig(char c) {
  return (int)c - (int)'0';
}

int solve(int pos, string &s) {  
  return to_dig(s[pos]);
}

string build() {
  ostringstream os;
  for (int j = 2; j <= 200000; ++j) {
    if (is_prime(j)) {
      os << to_string(j);
    }
  }
  return os.str(); 
}

int main() {  
  int m;
  cin >> m;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  string s = build();
  for (int i = 0; i < m; ++i) {    
    cout << solve(a[i] - 1, s);
  }
  cout << endl;
  return 0;
}