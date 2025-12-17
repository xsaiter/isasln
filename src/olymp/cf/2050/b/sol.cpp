#include <bits/stdc++.h>

using namespace std;

using L = long long;

bool solve(int n, vector<L> &a) {
  L s = accumulate(a.begin(), a.end(), 0LL);  
  if (s % n != 0) {
    return false;
  }
  L x = s / n;  
  L s1 = 0, m1 = 0, s2 = 0, m2 = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      s1 += a[i];
      m1++;
    } else {
      s2 += a[i];
      m2++;
    }
  }
  return x * m1 == s1 && x * m2 == s2;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<L> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << (solve(n, a) ? "YES" : "NO") << '\n';
  }
  cout << endl;
  return 0;
}