#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int m = 26;
  vector<int> a(m, 0);
  for (int i = 0; i < n; ++i) {
    int j = s[i] - 'a';
    a[j]++;
  }
  int mx = *max_element(begin(a), end(a));
  cout << (mx > k ? "NO" : "YES") << endl;
  return 0;
}