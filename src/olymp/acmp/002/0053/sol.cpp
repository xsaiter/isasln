#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(4, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int v = i * j;
      if (v % 5 == 0) {
        a[2]++;
      } else if (v % 3 == 0) {
        a[1]++;
      } else if (v % 2 == 0) {
        a[0]++;
      } else {
        a[3]++;
      }
    }
  }
  cout << "RED : " << a[0] << "\n";
  cout << "GREEN : " << a[1] << "\n";
  cout << "BLUE : " << a[2] << "\n";
  cout << "BLACK : " << a[3] << "\n";
  cout << endl;
  return 0;
}