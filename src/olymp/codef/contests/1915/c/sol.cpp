#include <bits/stdc++.h>

using namespace std;

bool solve(const vector<int> &a, int n) {
  long long s = 0;
  for (int i = 0; i < n; ++i) {
    s += a[i];
  }
  if (s == 1) {
    return true;
  }
  long long r = (long long)pow(s, 0.5);
  return r * r == s;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << (solve(a, n) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;  
}

