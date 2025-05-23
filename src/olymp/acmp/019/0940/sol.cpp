#include <bits/stdc++.h>

using namespace std;

int main() {
  int k;
  cin >> k;
  string s;
  cin >> s;  
  int n = (int)s.size();
  cout << s.substr(0, k - 1) + s.substr(k, n - k) << endl;
  return 0;
}