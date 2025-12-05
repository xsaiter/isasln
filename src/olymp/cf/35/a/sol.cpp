#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x;
  cin >> x;
  vector<int> a {0, 1, 2, 3};
  int p, q;
  while (cin) {
    cin >> p >> q;    
    cout << p << "-" << q << endl;
    swap(a[p], a[q]);
  }
  int res = 0;
  for (int i = 1; i < 4; ++i) {
    if (a[i] == x) { res = i; break; }
  }
  cout << res << endl;
  return 0;
}