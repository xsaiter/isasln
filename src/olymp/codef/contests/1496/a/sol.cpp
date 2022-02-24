#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int k, string &s) {
  int len = 0;  
  int i = 0, j = n - 1;
  while (i < j) {
    if (s[i] == s[j]) {
      ++len;
    }
  }
  
  if (n %
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool can = solve(n, k, s);
    if (can) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}