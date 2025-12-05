#include <bits/stdc++.h>

using namespace std;

int solve(int n, string &s) {
  int res = 0;
  vector<bool> a(26, false);
  for (int i = 0; i < n; ++i) {
    int j = (int)s[i] - 'A';
    if (a[j]) {
      res += 1;
    } else {
      res += 2;
      a[j] = true;
    }
  }
  return res;
}

int main() {
	int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(n, s) << '\n';
  }
  cout << endl;
  return 0;
}