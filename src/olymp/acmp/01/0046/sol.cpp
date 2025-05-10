#include <bits/stdc++.h>

using namespace std;

string e = "2.7182818284590452353602875";
char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int dig(char c) {
  return (int)c - (int)'0';
}
              
char from_dig(int x) {
  return digits[x];
}

string solve(int n) {
  if (n == 0) {
    return "3";
  }  
  if (n == 25) {
    return e;
  }
  int a = dig(e[n + 1]);
  int b = dig(e[n + 1 + 1]);
  if (b > 4) {
    ++a;
    e[n + 1] = from_dig(a);
  }  
  return e.substr(0, 2 + n);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;  
  cout << solve(n) << endl;
  return 0;
}