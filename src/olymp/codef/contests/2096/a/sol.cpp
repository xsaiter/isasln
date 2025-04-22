#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, string &s) {
  vector<int> a(n);
  int x = n, y = 1;    
  for (int i = n - 2; i >= 0; --i) {
    if (s[i] == '>') {
      a[i + 1] = x;
      --x;
    } else {
      a[i + 1] = y;
      ++y;
    }
  }
  a[0] = x;
  return a;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a = solve(n, s);
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}