#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  const int n = s.size();
  bool happy = false;
  auto f = [](char d) { return (int)(d - '0'); };
  if (n == 6) {
    int a = f(s[0]) + f(s[1]) + f(s[2]);
    int b = f(s[3]) + f(s[4]) + f(s[5]);
    happy = (a == b);
  }
  if (happy) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;
  return 0;
}