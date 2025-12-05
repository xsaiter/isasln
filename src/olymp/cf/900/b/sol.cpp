#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b, int c) {
  int i = 1;  
  int k = 0;
  while (k < 1000) {
    int x = a;
    int j = 0;
    while (x < b) {
      x *= 10;
      if (j > 0) {
        ++i;
        if (c == 0) return i - 1;
      }
      ++j;      
    }
    int d = (x - x % b) / b;
    if (d == c) return i;
    a = x - d * b;
    if (a == 0) {
      return (c == 0) ? (i + 1) : -1;
    }
    ++i; ++k;    
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b, c;
  cin >> a >> b >> c;  
  cout << solve(a, b, c) << endl;
  return 0;
}