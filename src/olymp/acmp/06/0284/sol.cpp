#include <bits/stdc++.h>

using namespace std;

struct P {
  int x, y;
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<P> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i].x >> b[i].y;
  }  
  for (int i = 0; i < m; ++i) {
    for (int j = b[i].x - 1; j <= b[i].y - 1; ++j) {
      cout << a[j] << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}