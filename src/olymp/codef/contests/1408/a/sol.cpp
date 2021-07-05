#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int gen(int a, int b, int c, int d, int e) {
  if (a != d && a != e) return a;  
  if (b != d && b != e) return b;
  return c;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    vi c(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> c[i];
    }
    vi p(n);
    p[0] = a[0];
    for (int i = 1; i < n; ++i) {
      int e = -1;
      if (i == n - 1) e = p[0];
      p[i] = gen(a[i], b[i], c[i], p[i - 1], e);
    }
    copy(begin(p), end(p), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
  cout << endl;
  return 0;
}