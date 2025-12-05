#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int a = atoi(string(1, s[0]).c_str());  
  int b = atoi(string(1, s[2]).c_str());
  int res;
  if (s[1] == '+') res = a + b; else res = a - b;
  cout << res << endl;
  return 0;
}