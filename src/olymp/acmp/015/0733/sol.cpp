#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }    
  set<int> x;
  int c = -INF;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= c) {
      c = a[i];
      x.insert(i);
    }    
  }
  c = -INF;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] > c) {
      c = a[i];
      x.insert(i);
    }    
  }
  vector<int> b;
  for (int i = 0; i < n; ++i) {
    if (x.contains(i)) {
      b.push_back(a[i]);
    }
  }
  int m = (int)b.size();
  cout << m << '\n';
  for (int i = 0; i < m; ++i) {
    cout << b[i] << ' ';
  }
  cout << endl;
  return 0;
}