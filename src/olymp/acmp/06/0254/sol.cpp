#include <bits/stdc++.h>

using namespace std;

struct R {
  int x, y;
};

vector<int> solve(int n, vector<int>& a, int m, vector<R>& b) {
  vector<int> c(n);
  
  return c;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<R> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i].x >> b[i].y;
  }
  vector<int> c = solve(n, a, m, b);
  for (int i = 0; i < n; ++i) {
    cout << c[i] << ' ';
  }
  cout << endl;
  return 0;
}